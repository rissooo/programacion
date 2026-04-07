<template>
  <div class="rounded-2xl overflow-hidden" style="border: 1px solid rgba(52,211,153,0.2)">
    <!-- Header -->
    <button
      @click="isOpen = !isOpen"
      class="section-header w-full flex items-center justify-between px-5 py-4 cursor-pointer"
      style="border-radius: 1rem 1rem 0 0"
    >
      <div class="flex items-center gap-3">
        <div class="w-8 h-8 rounded-lg flex items-center justify-center"
             style="background: rgba(52,211,153,0.15); border: 1px solid rgba(52,211,153,0.3)">
          <svg xmlns="http://www.w3.org/2000/svg" class="w-4 h-4 text-emerald-400" viewBox="0 0 20 20" fill="currentColor">
            <path fill-rule="evenodd" d="M16.707 5.293a1 1 0 00-1.414 0L8 12.586 4.707 9.293a1 1 0 00-1.414 1.414l4 4a1 1 0 001.414 0l8-8a1 1 0 000-1.414z" clip-rule="evenodd" />
          </svg>
        </div>
        <span class="text-white font-semibold text-base" style="font-family: 'Sora', sans-serif;">Completadas</span>
        <span class="badge-completed text-xs font-bold px-2.5 py-0.5 rounded-full">
          {{ store.completedTasks.length }}
        </span>
      </div>
      <svg
        :class="['w-5 h-5 text-white/40 transition-transform duration-200', isOpen ? 'rotate-180' : '']"
        xmlns="http://www.w3.org/2000/svg" viewBox="0 0 20 20" fill="currentColor"
      >
        <path fill-rule="evenodd" d="M5.293 7.293a1 1 0 011.414 0L10 10.586l3.293-3.293a1 1 0 111.414 1.414l-4 4a1 1 0 01-1.414 0l-4-4a1 1 0 010-1.414z" clip-rule="evenodd" />
      </svg>
    </button>

    <!-- Body -->
    <Transition
      enter-active-class="transition-all duration-200 ease-out"
      enter-from-class="opacity-0"
      enter-to-class="opacity-100"
      leave-active-class="transition-all duration-150 ease-in"
      leave-from-class="opacity-100"
      leave-to-class="opacity-0"
    >
      <div v-show="isOpen" class="p-3 space-y-2.5" style="background: rgba(0,0,0,0.2)">
        <template v-if="store.completedTasks.length">
          <TaskCard v-for="task in store.completedTasks" :key="task.id" :task="task" />
        </template>
        <div v-else class="text-center py-10">
          <div class="text-4xl mb-3">📭</div>
          <p class="text-white/50 text-sm font-medium">Todavía no completaste ninguna tarea</p>
          <p class="text-white/25 text-xs mt-1">¡Empezá marcando una como completada!</p>
        </div>
      </div>
    </Transition>
  </div>
</template>

<script setup>
import { ref, watch } from 'vue'
import { useTaskStore } from '../stores/taskStore'
import TaskCard from './TaskCard.vue'

const store = useTaskStore()
const isOpen = ref(false)

watch(() => store.activeSection, (section) => {
  if (section === 'completed') isOpen.value = true
})
</script>
