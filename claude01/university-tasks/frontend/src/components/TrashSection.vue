<template>
  <div class="glass-card rounded-2xl overflow-hidden">
    <!-- Header -->
    <div class="px-5 py-4 flex items-center justify-between"
         style="border-bottom: 1px solid rgba(255,255,255,0.08)">
      <div class="flex items-center gap-2.5">
        <span class="text-2xl">🗑️</span>
        <div>
          <h2 class="text-white font-bold text-base leading-tight" style="font-family: 'Sora', sans-serif;">
            Papelera
          </h2>
          <p class="text-white/30 text-xs mt-0.5">Se eliminan a los 30 días</p>
        </div>
      </div>
      <span class="text-xs font-bold px-2.5 py-0.5 rounded-full"
            style="background: rgba(255,255,255,0.08); color: rgba(255,255,255,0.45); border: 1px solid rgba(255,255,255,0.12)">
        {{ store.trash.length }}
      </span>
    </div>

    <!-- Empty state -->
    <div v-if="!store.trash.length" class="text-center py-10 px-4">
      <div class="text-3xl mb-2 opacity-30">🗑️</div>
      <p class="text-white/30 text-sm">La papelera está vacía</p>
    </div>

    <!-- Task list -->
    <div v-else class="p-3 space-y-2">
      <div
        v-for="task in store.trash"
        :key="task.id"
        class="rounded-xl p-3.5 transition-all duration-150"
        style="background: rgba(255,255,255,0.04); border: 1px solid rgba(255,255,255,0.07)"
      >
        <!-- Name + badge días -->
        <div class="flex items-start justify-between gap-2 mb-1">
          <p class="text-white/60 text-sm font-medium leading-snug line-through">{{ task.name }}</p>
          <span
            :class="task.days_remaining <= 3 ? 'text-red-400' : task.days_remaining <= 10 ? 'text-amber-400' : 'text-white/30'"
            class="text-xs font-semibold whitespace-nowrap shrink-0"
          >
            {{ task.days_remaining }}d
          </span>
        </div>

        <p class="text-white/25 text-xs leading-relaxed mb-3 line-clamp-2">{{ task.description }}</p>

        <!-- Acciones -->
        <div class="flex gap-2">
          <button
            @click="store.restoreTask(task.id)"
            @mouseenter="hovered = `${task.id}-restore`"
            @mouseleave="hovered = null"
            title="Restaurar"
            class="flex-1 flex items-center justify-center gap-1.5 py-1.5 rounded-lg text-xs font-semibold cursor-pointer transition-all duration-150"
            :style="hovered === `${task.id}-restore`
              ? 'background: rgba(139,92,246,0.28); border: 1px solid rgba(139,92,246,0.3); color: #a78bfa'
              : 'background: rgba(139,92,246,0.15); border: 1px solid rgba(139,92,246,0.3); color: #a78bfa'"
          >
            <svg xmlns="http://www.w3.org/2000/svg" class="w-3.5 h-3.5" fill="none" viewBox="0 0 24 24" stroke="currentColor" stroke-width="2.5">
              <path stroke-linecap="round" stroke-linejoin="round" d="M3 10h10a8 8 0 018 8v2M3 10l6 6m-6-6l6-6" />
            </svg>
            Restaurar
          </button>
          <button
            @click="store.permanentDelete(task.id)"
            @mouseenter="hovered = `${task.id}-delete`"
            @mouseleave="hovered = null"
            title="Eliminar permanentemente"
            class="w-8 h-8 flex items-center justify-center rounded-lg cursor-pointer transition-all duration-150"
            :style="hovered === `${task.id}-delete`
              ? 'background: rgba(239,68,68,0.25); border: 1px solid rgba(239,68,68,0.25); color: #f87171'
              : 'background: rgba(239,68,68,0.12); border: 1px solid rgba(239,68,68,0.25); color: #f87171'"
          >
            <svg xmlns="http://www.w3.org/2000/svg" class="w-4 h-4" viewBox="0 0 20 20" fill="currentColor">
              <path fill-rule="evenodd" d="M4.293 4.293a1 1 0 011.414 0L10 8.586l4.293-4.293a1 1 0 111.414 1.414L11.414 10l4.293 4.293a1 1 0 01-1.414 1.414L10 11.414l-4.293 4.293a1 1 0 01-1.414-1.414L8.586 10 4.293 5.707a1 1 0 010-1.414z" clip-rule="evenodd" />
            </svg>
          </button>
        </div>
      </div>
    </div>

    <!-- Vaciar papelera -->
    <div v-if="store.trash.length" class="px-3 pb-3">
      <button
        @click="store.emptyTrash()"
        @mouseenter="hoveredEmpty = true"
        @mouseleave="hoveredEmpty = false"
        class="w-full py-2 rounded-xl text-xs font-semibold cursor-pointer transition-all duration-150"
        :style="hoveredEmpty
          ? 'background: rgba(239,68,68,0.2); border: 1px solid rgba(239,68,68,0.2); color: #f87171'
          : 'background: rgba(239,68,68,0.1); border: 1px solid rgba(239,68,68,0.2); color: #f87171'"
      >
        Vaciar papelera
      </button>
    </div>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import { useTaskStore } from '../stores/taskStore'

const store = useTaskStore()
const hovered = ref(null)
const hoveredEmpty = ref(false)
</script>
