<template>
  <div class="task-card p-4 flex items-start gap-4">
    <!-- Ícono de estado -->
    <div class="shrink-0 mt-0.5">
      <div v-if="task.status === 'completed'"
           class="w-9 h-9 rounded-full flex items-center justify-center"
           style="background: rgba(52,211,153,0.15); border: 1px solid rgba(52,211,153,0.35)">
        <svg xmlns="http://www.w3.org/2000/svg" class="w-5 h-5 text-emerald-400" viewBox="0 0 20 20" fill="currentColor">
          <path fill-rule="evenodd" d="M16.707 5.293a1 1 0 00-1.414 0L8 12.586 4.707 9.293a1 1 0 00-1.414 1.414l4 4a1 1 0 001.414 0l8-8a1 1 0 000-1.414z" clip-rule="evenodd" />
        </svg>
      </div>
      <div v-else
           class="w-9 h-9 rounded-full flex items-center justify-center"
           style="background: rgba(251,191,36,0.15); border: 1px solid rgba(251,191,36,0.35)">
        <svg xmlns="http://www.w3.org/2000/svg" class="w-5 h-5 text-amber-400" fill="none" viewBox="0 0 24 24" stroke="currentColor" stroke-width="2">
          <path stroke-linecap="round" stroke-linejoin="round" d="M12 8v4l3 3m6-3a9 9 0 11-18 0 9 9 0 0118 0z" />
        </svg>
      </div>
    </div>

    <!-- Contenido -->
    <div class="flex-1 min-w-0">
      <div class="flex flex-wrap items-center gap-2 mb-1">
        <h3 :class="['font-semibold text-base leading-snug', task.status === 'completed' ? 'text-white/50 line-through' : 'text-white']">
          {{ task.name }}
        </h3>
        <span :class="['text-xs font-semibold px-2.5 py-0.5 rounded-full', task.status === 'completed' ? 'badge-completed' : 'badge-pending']">
          {{ task.status === 'completed' ? 'Completada' : 'Pendiente' }}
        </span>
      </div>
      <p :class="['text-sm leading-relaxed mb-2', task.status === 'completed' ? 'text-white/30' : 'text-white/55']">
        {{ task.description }}
      </p>
      <div class="flex items-center gap-3 flex-wrap">
        <p class="text-white/25 text-xs flex items-center gap-1">
          <svg xmlns="http://www.w3.org/2000/svg" class="w-3.5 h-3.5" fill="none" viewBox="0 0 24 24" stroke="currentColor" stroke-width="2">
            <path stroke-linecap="round" stroke-linejoin="round" d="M8 7V3m8 4V3m-9 8h10M5 21h14a2 2 0 002-2V7a2 2 0 00-2-2H5a2 2 0 00-2 2v12a2 2 0 002 2z" />
          </svg>
          Creada: {{ formatDate(task.created_at) }}
        </p>
        <p v-if="task.due_date" :class="['text-xs font-semibold flex items-center gap-1', dueDateColor]">
          <svg xmlns="http://www.w3.org/2000/svg" class="w-3.5 h-3.5" fill="none" viewBox="0 0 24 24" stroke="currentColor" stroke-width="2">
            <path stroke-linecap="round" stroke-linejoin="round" d="M12 8v4l3 3m6-3a9 9 0 11-18 0 9 9 0 0118 0z" />
          </svg>
          Entrega: {{ formatDate(task.due_date) }}
        </p>
      </div>
    </div>

    <!-- Acciones -->
    <div class="flex items-center gap-1.5 shrink-0">
      <button
        v-if="task.status === 'pending'"
        @click="store.completeTask(task.id)"
        @mouseenter="hovered = 'complete'"
        @mouseleave="hovered = null"
        title="Marcar como completada"
        class="w-9 h-9 rounded-xl flex items-center justify-center cursor-pointer transition-all duration-150"
        :style="hovered === 'complete'
          ? 'background: rgba(52,211,153,0.3); border: 1px solid rgba(52,211,153,0.3)'
          : 'background: rgba(52,211,153,0.15); border: 1px solid rgba(52,211,153,0.3)'"
      >
        <svg xmlns="http://www.w3.org/2000/svg" class="w-5 h-5 text-emerald-400" viewBox="0 0 20 20" fill="currentColor">
          <path fill-rule="evenodd" d="M16.707 5.293a1 1 0 00-1.414 0L8 12.586 4.707 9.293a1 1 0 00-1.414 1.414l4 4a1 1 0 001.414 0l8-8a1 1 0 000-1.414z" clip-rule="evenodd" />
        </svg>
      </button>

      <button
        v-if="task.status === 'completed'"
        @click="handleSetPending"
        @mouseenter="hovered = 'pending'"
        @mouseleave="hovered = null"
        title="Volver a pendiente"
        class="w-9 h-9 rounded-xl flex items-center justify-center cursor-pointer transition-all duration-150"
        :style="hovered === 'pending'
          ? 'background: rgba(255,255,255,0.15); border: 1px solid rgba(255,255,255,0.15)'
          : 'background: rgba(255,255,255,0.08); border: 1px solid rgba(255,255,255,0.15)'"
      >
        <svg xmlns="http://www.w3.org/2000/svg" class="w-5 h-5 text-white/60" fill="none" viewBox="0 0 24 24" stroke="currentColor" stroke-width="2">
          <path stroke-linecap="round" stroke-linejoin="round" d="M3 10h10a8 8 0 018 8v2M3 10l6 6m-6-6l6-6" />
        </svg>
      </button>

      <button
        @click="store.deleteTask(task.id)"
        @mouseenter="hovered = 'delete'"
        @mouseleave="hovered = null"
        title="Eliminar tarea"
        class="w-9 h-9 rounded-xl flex items-center justify-center cursor-pointer transition-all duration-150"
        :style="hovered === 'delete'
          ? 'background: rgba(239,68,68,0.3); border: 1px solid rgba(239,68,68,0.3)'
          : 'background: rgba(239,68,68,0.15); border: 1px solid rgba(239,68,68,0.3)'"
      >
        <svg xmlns="http://www.w3.org/2000/svg" class="w-5 h-5 text-red-400" viewBox="0 0 20 20" fill="currentColor">
          <path fill-rule="evenodd" d="M9 2a1 1 0 00-.894.553L7.382 4H4a1 1 0 000 2v10a2 2 0 002 2h8a2 2 0 002-2V6a1 1 0 100-2h-3.382l-.724-1.447A1 1 0 0011 2H9zM7 8a1 1 0 012 0v6a1 1 0 11-2 0V8zm5-1a1 1 0 00-1 1v6a1 1 0 102 0V8a1 1 0 00-1-1z" clip-rule="evenodd" />
        </svg>
      </button>
    </div>
  </div>
</template>

<script setup>
import { ref, computed } from 'vue'
import { useTaskStore } from '../stores/taskStore'

const props = defineProps({
  task: { type: Object, required: true },
})

const store = useTaskStore()
const hovered = ref(null)

function formatDate(dateStr) {
  if (!dateStr) return ''
  const d = new Date(dateStr + (dateStr.length === 10 ? 'T00:00:00' : ''))
  return d.toLocaleDateString('es-AR', { day: '2-digit', month: '2-digit', year: 'numeric' })
}

const dueDateColor = computed(() => {
  if (!props.task.due_date || props.task.status === 'completed') return 'text-white/30'
  const today = new Date(); today.setHours(0,0,0,0)
  const due = new Date(props.task.due_date + 'T00:00:00')
  const diff = Math.ceil((due - today) / 86400000)
  if (diff < 0) return 'text-red-400'
  if (diff <= 3) return 'text-orange-400'
  if (diff <= 7) return 'text-amber-400'
  return 'text-white/40'
})

async function handleSetPending() {
  await store.setPending(props.task.id)
  store.setActiveSection('pending')
}
</script>
