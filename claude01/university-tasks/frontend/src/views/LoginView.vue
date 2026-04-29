<template>
  <div class="min-h-screen flex items-center justify-center px-4">
    <div class="w-full max-w-sm">
      <!-- Logo -->
      <div class="text-center mb-8">
        <div class="inline-flex items-center justify-center w-16 h-16 rounded-2xl mb-4 glow-purple"
             style="background: linear-gradient(135deg, #7c3aed, #4f46e5)">
          <svg xmlns="http://www.w3.org/2000/svg" class="w-8 h-8 text-white" fill="none" viewBox="0 0 24 24" stroke="currentColor" stroke-width="2">
            <path stroke-linecap="round" stroke-linejoin="round" d="M12 6.042A8.967 8.967 0 006 3.75c-1.052 0-2.062.18-3 .512v14.25A8.987 8.987 0 016 18c2.305 0 4.408.867 6 2.292m0-14.25a8.966 8.966 0 016-2.292c1.052 0 2.062.18 3 .512v14.25A8.987 8.987 0 0018 18a8.966 8.966 0 00-6 2.292m0-14.25v14.25" />
          </svg>
        </div>
        <h1 class="text-3xl font-bold text-white mb-1" style="font-family: 'Sora', sans-serif; letter-spacing: -0.5px;">
          Gestor de Tareas
        </h1>
        <p class="text-indigo-300 text-sm font-medium">Organizá tu vida universitaria</p>
      </div>

      <!-- Card -->
      <div class="glass-card rounded-2xl p-7">
        <!-- Tabs -->
        <div class="flex rounded-xl p-1 mb-6" style="background: rgba(255,255,255,0.05)">
          <button
            @click="mode = 'login'"
            :class="['flex-1 py-2 rounded-lg text-sm font-semibold transition-all duration-200 cursor-pointer',
                     mode === 'login' ? 'text-white' : 'text-white/40 hover:text-white/70']"
            :style="mode === 'login' ? 'background: rgba(124,58,237,0.6)' : ''"
          >
            Iniciar sesión
          </button>
          <button
            @click="mode = 'register'"
            :class="['flex-1 py-2 rounded-lg text-sm font-semibold transition-all duration-200 cursor-pointer',
                     mode === 'register' ? 'text-white' : 'text-white/40 hover:text-white/70']"
            :style="mode === 'register' ? 'background: rgba(124,58,237,0.6)' : ''"
          >
            Registrarse
          </button>
        </div>

        <!-- Error -->
        <div v-if="error" class="flex items-center gap-2 rounded-xl px-4 py-3 mb-4 text-sm text-red-300"
             style="background: rgba(239,68,68,0.12); border: 1px solid rgba(239,68,68,0.3)">
          <svg xmlns="http://www.w3.org/2000/svg" class="w-4 h-4 shrink-0" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M12 9v2m0 4h.01" />
          </svg>
          {{ error }}
        </div>

        <!-- Form -->
        <div class="space-y-4">
          <div>
            <label class="block text-white/60 text-xs font-semibold uppercase tracking-wider mb-2">Email</label>
            <input
              v-model="email"
              type="email"
              placeholder="tu@email.com"
              class="glass-input w-full rounded-xl px-4 py-3 text-sm"
              @keydown.enter="handleSubmit"
            />
          </div>

          <div>
            <label class="block text-white/60 text-xs font-semibold uppercase tracking-wider mb-2">Contraseña</label>
            <input
              v-model="password"
              type="password"
              :placeholder="mode === 'register' ? 'Mínimo 8 caracteres' : '••••••••'"
              class="glass-input w-full rounded-xl px-4 py-3 text-sm"
              @keydown.enter="handleSubmit"
            />
            <p v-if="mode === 'register' && password.length > 0 && password.length < 8"
               class="text-amber-400 text-xs mt-1.5 pl-1">
              La contraseña debe tener al menos 8 caracteres
            </p>
          </div>

          <button
            @click="handleSubmit"
            :disabled="loading || !email || !password || (mode === 'register' && password.length < 8)"
            class="btn-primary w-full flex items-center justify-center gap-2 text-sm mt-2"
          >
            <svg v-if="loading" class="animate-spin w-4 h-4" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24">
              <circle class="opacity-25" cx="12" cy="12" r="10" stroke="currentColor" stroke-width="4"></circle>
              <path class="opacity-75" fill="currentColor" d="M4 12a8 8 0 018-8V0C5.373 0 0 5.373 0 12h4z"></path>
            </svg>
            {{ loading ? 'Cargando...' : (mode === 'login' ? 'Iniciar sesión' : 'Crear cuenta') }}
          </button>
        </div>
      </div>
    </div>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import { useAuthStore } from '../stores/authStore'

const auth = useAuthStore()
const mode = ref('login')
const email = ref('')
const password = ref('')
const loading = ref(false)
const error = ref('')

async function handleSubmit() {
  if (!email.value || !password.value) return
  if (mode.value === 'register' && password.value.length < 8) return
  error.value = ''
  loading.value = true
  try {
    if (mode.value === 'login') {
      await auth.login(email.value, password.value)
    } else {
      await auth.register(email.value, password.value)
    }
  } catch (e) {
    error.value = e.message
  } finally {
    loading.value = false
  }
}
</script>
