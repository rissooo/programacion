<template>
  <div class="glass-card rounded-2xl overflow-visible mt-4">
    <!-- Header -->
    <div class="px-4 py-3 flex items-center justify-between"
         style="border-bottom: 1px solid rgba(255,255,255,0.08)">
      <button @click="prevMonth" class="w-7 h-7 rounded-lg flex items-center justify-center cursor-pointer transition-all"
              style="background: rgba(255,255,255,0.06); border: 1px solid rgba(255,255,255,0.1)"
              onmouseover="this.style.background='rgba(255,255,255,0.14)'"
              onmouseout="this.style.background='rgba(255,255,255,0.06)'">
        <svg xmlns="http://www.w3.org/2000/svg" class="w-3.5 h-3.5 text-white/60" viewBox="0 0 20 20" fill="currentColor">
          <path fill-rule="evenodd" d="M12.707 5.293a1 1 0 010 1.414L9.414 10l3.293 3.293a1 1 0 01-1.414 1.414l-4-4a1 1 0 010-1.414l4-4a1 1 0 011.414 0z" clip-rule="evenodd" />
        </svg>
      </button>
      <div class="text-center">
        <p class="text-white font-semibold text-sm capitalize" style="font-family: 'Sora', sans-serif;">
          {{ monthLabel }}
        </p>
      </div>
      <button @click="nextMonth" class="w-7 h-7 rounded-lg flex items-center justify-center cursor-pointer transition-all"
              style="background: rgba(255,255,255,0.06); border: 1px solid rgba(255,255,255,0.1)"
              onmouseover="this.style.background='rgba(255,255,255,0.14)'"
              onmouseout="this.style.background='rgba(255,255,255,0.06)'">
        <svg xmlns="http://www.w3.org/2000/svg" class="w-3.5 h-3.5 text-white/60" viewBox="0 0 20 20" fill="currentColor">
          <path fill-rule="evenodd" d="M7.293 14.707a1 1 0 010-1.414L10.586 10 7.293 6.707a1 1 0 011.414-1.414l4 4a1 1 0 010 1.414l-4 4a1 1 0 01-1.414 0z" clip-rule="evenodd" />
        </svg>
      </button>
    </div>

    <!-- Day names -->
    <div class="grid grid-cols-7 px-3 pt-3 pb-1">
      <div v-for="d in dayNames" :key="d" class="text-center text-white/30 text-xs font-semibold py-1">
        {{ d }}
      </div>
    </div>

    <!-- Day cells -->
    <div class="grid grid-cols-7 gap-0.5 px-3 pb-3">
      <!-- Empty slots before first day -->
      <div v-for="n in firstWeekdayOffset" :key="'empty-' + n"></div>

      <!-- Days -->
      <div
        v-for="day in daysInMonth"
        :key="day"
        class="relative flex items-center justify-center"
        style="aspect-ratio: 1;"
        @mouseenter="hoveredDay = hasTasks(day) ? day : null"
        @mouseleave="hoveredDay = null"
      >
        <!-- Day button -->
        <div
          :class="[
            'w-7 h-7 rounded-lg flex items-center justify-center text-xs font-medium cursor-default transition-all',
            isToday(day)
              ? 'text-white font-bold'
              : hasTasks(day)
                ? 'text-white cursor-pointer'
                : 'text-white/35',
          ]"
          :style="dayStyle(day)"
        >
          {{ day }}
        </div>

        <!-- Dot indicator -->
        <span
          v-if="hasTasks(day)"
          class="absolute bottom-0.5 left-1/2 -translate-x-1/2 w-1 h-1 rounded-full"
          :style="dotStyle(day)"
        ></span>

        <!-- Tooltip -->
        <div
          v-if="hoveredDay === day"
          class="absolute z-50 left-1/2 bottom-full mb-2 -translate-x-1/2 pointer-events-none"
          style="min-width: 180px; max-width: 220px;"
        >
          <div class="rounded-xl p-3 shadow-2xl"
               style="background: #1e1b4b; border: 1px solid rgba(139,92,246,0.4); box-shadow: 0 8px 32px rgba(0,0,0,0.5)">
            <p class="text-violet-300 text-xs font-bold uppercase tracking-wider mb-2">
              {{ formatDayHeader(day) }}
            </p>
            <div v-for="task in getTasksForDay(day)" :key="task.id" class="mb-2 last:mb-0">
              <p class="text-white text-xs font-semibold leading-snug">{{ task.name }}</p>
              <p class="text-white/50 text-xs leading-snug mt-0.5">{{ task.description }}</p>
              <span :class="['text-xs font-semibold mt-1 inline-block', task.status === 'completed' ? 'text-emerald-400' : 'text-amber-400']">
                {{ task.status === 'completed' ? '✓ Completada' : '⏳ Pendiente' }}
              </span>
            </div>
            <!-- Arrow -->
            <div class="absolute left-1/2 -translate-x-1/2 top-full w-0 h-0"
                 style="border-left: 6px solid transparent; border-right: 6px solid transparent; border-top: 6px solid rgba(139,92,246,0.4)"></div>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script setup>
import { ref, computed } from 'vue'
import { useTaskStore } from '../stores/taskStore'

const store = useTaskStore()
const today = new Date()
const currentYear = ref(today.getFullYear())
const currentMonth = ref(today.getMonth()) // 0-indexed
const hoveredDay = ref(null)

const dayNames = ['Lu', 'Ma', 'Mi', 'Ju', 'Vi', 'Sá', 'Do']

const monthLabel = computed(() => {
  const d = new Date(currentYear.value, currentMonth.value, 1)
  return d.toLocaleDateString('es-AR', { month: 'long', year: 'numeric' })
})

const daysInMonth = computed(() => {
  return new Date(currentYear.value, currentMonth.value + 1, 0).getDate()
})

const firstWeekdayOffset = computed(() => {
  // Monday=0 ... Sunday=6
  const day = new Date(currentYear.value, currentMonth.value, 1).getDay()
  return day === 0 ? 6 : day - 1
})

// Map "YYYY-MM-DD" -> task[]
const tasksByDate = computed(() => {
  const map = {}
  for (const task of store.tasks) {
    if (!task.due_date) continue
    const key = task.due_date.slice(0, 10)
    if (!map[key]) map[key] = []
    map[key].push(task)
  }
  return map
})

function dateKey(day) {
  const m = String(currentMonth.value + 1).padStart(2, '0')
  const d = String(day).padStart(2, '0')
  return `${currentYear.value}-${m}-${d}`
}

function hasTasks(day) {
  return !!tasksByDate.value[dateKey(day)]?.length
}

function getTasksForDay(day) {
  return tasksByDate.value[dateKey(day)] || []
}

function isToday(day) {
  return (
    day === today.getDate() &&
    currentMonth.value === today.getMonth() &&
    currentYear.value === today.getFullYear()
  )
}

function dayStyle(day) {
  if (isToday(day)) {
    return 'background: linear-gradient(135deg, #7c3aed, #4f46e5); box-shadow: 0 0 10px rgba(124,58,237,0.5);'
  }
  if (hasTasks(day)) {
    const tasks = getTasksForDay(day)
    const allDone = tasks.every(t => t.status === 'completed')
    if (allDone) return 'background: rgba(52,211,153,0.15); border: 1px solid rgba(52,211,153,0.3);'
    return 'background: rgba(251,191,36,0.15); border: 1px solid rgba(251,191,36,0.3);'
  }
  return ''
}

function dotStyle(day) {
  const tasks = getTasksForDay(day)
  const allDone = tasks.every(t => t.status === 'completed')
  return allDone ? 'background: #34d399;' : 'background: #fbbf24;'
}

function formatDayHeader(day) {
  const d = new Date(currentYear.value, currentMonth.value, day)
  return d.toLocaleDateString('es-AR', { weekday: 'short', day: 'numeric', month: 'short' })
}

function prevMonth() {
  if (currentMonth.value === 0) {
    currentMonth.value = 11
    currentYear.value--
  } else {
    currentMonth.value--
  }
  hoveredDay.value = null
}

function nextMonth() {
  if (currentMonth.value === 11) {
    currentMonth.value = 0
    currentYear.value++
  } else {
    currentMonth.value++
  }
  hoveredDay.value = null
}
</script>
