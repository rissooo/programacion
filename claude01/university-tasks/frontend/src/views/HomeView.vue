<template>
  <div class="min-h-screen py-8 px-4">
    <!-- Header -->
    <header class="max-w-7xl mx-auto mb-8 text-center">
      <div class="inline-flex items-center justify-center w-16 h-16 rounded-2xl mb-4 glow-purple"
           style="background: linear-gradient(135deg, #7c3aed, #4f46e5)">
        <svg xmlns="http://www.w3.org/2000/svg" class="w-8 h-8 text-white" fill="none" viewBox="0 0 24 24" stroke="currentColor" stroke-width="2">
          <path stroke-linecap="round" stroke-linejoin="round" d="M12 6.042A8.967 8.967 0 006 3.75c-1.052 0-2.062.18-3 .512v14.25A8.987 8.987 0 016 18c2.305 0 4.408.867 6 2.292m0-14.25a8.966 8.966 0 016-2.292c1.052 0 2.062.18 3 .512v14.25A8.987 8.987 0 0018 18a8.966 8.966 0 00-6 2.292m0-14.25v14.25" />
        </svg>
      </div>
      <h1 class="text-4xl font-bold text-white mb-2" style="font-family: 'Sora', sans-serif; letter-spacing: -0.5px;">
        Gestor de Tareas
      </h1>
      <p class="text-indigo-300 text-base font-medium">Organizá tu vida universitaria</p>
      <p class="text-white/30 text-xs mt-1">{{ auth.userEmail }}</p>

      <!-- Stats bar -->
      <div class="flex items-center justify-center gap-6 mt-6">
        <div class="glass rounded-2xl px-5 py-2.5 flex items-center gap-2.5">
          <span class="w-2.5 h-2.5 rounded-full bg-emerald-400 inline-block"></span>
          <span class="text-white/70 text-sm">Completadas</span>
          <span class="text-white font-bold text-sm">{{ store.completedTasks.length }}</span>
        </div>
        <div class="glass rounded-2xl px-5 py-2.5 flex items-center gap-2.5">
          <span class="w-2.5 h-2.5 rounded-full bg-amber-400 inline-block"></span>
          <span class="text-white/70 text-sm">Pendientes</span>
          <span class="text-white font-bold text-sm">{{ store.pendingTasks.length }}</span>
        </div>
      </div>

      <!-- Logout -->
      <div class="flex justify-center mt-4">
        <button
          @click="auth.logout()"
          class="text-xs text-white/30 hover:text-white/60 transition-colors cursor-pointer px-3 py-1.5 rounded-lg"
          style="border: 1px solid rgba(255,255,255,0.08)"
        >
          Cerrar sesión
        </button>
      </div>
    </header>

    <!-- Error -->
    <div class="max-w-7xl mx-auto mb-4" v-if="store.error">
      <div class="flex items-center gap-3 rounded-xl px-5 py-3.5 text-sm text-red-300"
           style="background: rgba(239,68,68,0.12); border: 1px solid rgba(239,68,68,0.3)">
        <svg xmlns="http://www.w3.org/2000/svg" class="w-5 h-5 shrink-0" fill="none" viewBox="0 0 24 24" stroke="currentColor">
          <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M12 9v2m0 4h.01M10.29 3.86L1.82 18a2 2 0 001.71 3h16.94a2 2 0 001.71-3L13.71 3.86a2 2 0 00-3.42 0z" />
        </svg>
        {{ store.error }}
        <button @click="store.error = null" class="ml-auto text-red-400 hover:text-red-200 cursor-pointer">✕</button>
      </div>
    </div>

    <!-- 3-column layout -->
    <main class="max-w-7xl mx-auto flex gap-5 items-start">

      <!-- Col 1: Nueva tarea -->
      <div class="w-72 shrink-0">
        <TaskForm />
      </div>

      <!-- Col 2: Completadas + Pendientes -->
      <div class="flex-1 space-y-5">
        <div v-if="store.loading" class="text-center py-12">
          <div class="inline-flex items-center gap-3 text-indigo-300 text-sm">
            <svg class="animate-spin w-5 h-5" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24">
              <circle class="opacity-25" cx="12" cy="12" r="10" stroke="currentColor" stroke-width="4"></circle>
              <path class="opacity-75" fill="currentColor" d="M4 12a8 8 0 018-8V0C5.373 0 0 5.373 0 12h4z"></path>
            </svg>
            Cargando tareas...
          </div>
        </div>
        <template v-else>
          <CompletedSection />
          <PendingSection />
        </template>
      </div>

      <!-- Col 3: Papelera + Calendario -->
      <div class="w-64 shrink-0">
        <TrashSection />
        <CalendarSection />
      </div>

    </main>
  </div>
</template>

<script setup>
import { onMounted } from 'vue'
import { useTaskStore } from '../stores/taskStore'
import { useAuthStore } from '../stores/authStore'
import TaskForm from '../components/TaskForm.vue'
import PendingSection from '../components/PendingSection.vue'
import CompletedSection from '../components/CompletedSection.vue'
import TrashSection from '../components/TrashSection.vue'
import CalendarSection from '../components/CalendarSection.vue'

const store = useTaskStore()
const auth = useAuthStore()

onMounted(() => store.fetchTasks())
</script>
