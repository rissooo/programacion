<template>
  <div class="glass-card rounded-2xl p-6">
    <div class="mb-5">
      <h2 class="text-white font-bold text-lg" style="font-family: 'Sora', sans-serif;">Nueva Tarea</h2>
    </div>

    <div class="space-y-4">
      <!-- Nombre -->
      <div>
        <label class="block text-white/60 text-xs font-semibold uppercase tracking-wider mb-2">
          Nombre <span class="text-violet-400">*</span>
        </label>
        <input
          v-model="name"
          type="text"
          placeholder="Ej: Trabajo práctico de Cálculo"
          class="glass-input w-full rounded-xl px-4 py-3 text-sm"
        />
        <p v-if="showErrors && !name.trim()" class="text-red-400 text-xs mt-1.5 flex items-center gap-1">
          <svg xmlns="http://www.w3.org/2000/svg" class="w-3.5 h-3.5" fill="none" viewBox="0 0 24 24" stroke="currentColor"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M12 9v2m0 4h.01" /></svg>
          El nombre es obligatorio
        </p>
      </div>

      <!-- Descripción -->
      <div>
        <label class="block text-white/60 text-xs font-semibold uppercase tracking-wider mb-2">
          Descripción <span class="text-violet-400">*</span>
        </label>
        <textarea
          v-model="description"
          rows="3"
          placeholder="¿En qué consiste esta tarea?"
          class="glass-input w-full rounded-xl px-4 py-3 text-sm resize-none"
        ></textarea>
        <p v-if="showErrors && !description.trim()" class="text-red-400 text-xs mt-1.5 flex items-center gap-1">
          <svg xmlns="http://www.w3.org/2000/svg" class="w-3.5 h-3.5" fill="none" viewBox="0 0 24 24" stroke="currentColor"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M12 9v2m0 4h.01" /></svg>
          La descripción es obligatoria
        </p>
      </div>

      <!-- Fecha de entrega -->
      <div>
        <label class="block text-white/60 text-xs font-semibold uppercase tracking-wider mb-2">
          Fecha de entrega <span class="text-violet-400">*</span>
        </label>
        <div class="flex gap-2 w-full">
          <input
            v-model="dueDay"
            type="text"
            inputmode="numeric"
            maxlength="2"
            placeholder="Día"
            class="glass-input min-w-0 flex-1 rounded-xl px-4 py-3 text-sm"
          />
          <input
            v-model="dueMonthText"
            type="text"
            placeholder="Mes"
            class="glass-input min-w-0 flex-1 rounded-xl px-4 py-3 text-sm"
          />
        </div>

        <!-- Preview de año automático -->
        <p v-if="computedDueDate" class="text-white/30 text-xs mt-1.5 pl-1">
          📅 {{ dueDay }} de {{ monthNamesDisplay[parsedMonth - 1] }} de {{ resolvedYear }}
        </p>

        <p v-if="showErrors && !computedDueDate" class="text-red-400 text-xs mt-1.5 flex items-center gap-1">
          <svg xmlns="http://www.w3.org/2000/svg" class="w-3.5 h-3.5" fill="none" viewBox="0 0 24 24" stroke="currentColor"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M12 9v2m0 4h.01" /></svg>
          La fecha de entrega es obligatoria
        </p>
      </div>

      <!-- Botón -->
      <button
        @click="handleSubmit"
        :disabled="!name.trim() || !description.trim() || !computedDueDate || loading"
        class="btn-primary w-full flex items-center justify-center gap-2 text-sm"
      >
        <svg v-if="loading" class="animate-spin w-4 h-4" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24">
          <circle class="opacity-25" cx="12" cy="12" r="10" stroke="currentColor" stroke-width="4"></circle>
          <path class="opacity-75" fill="currentColor" d="M4 12a8 8 0 018-8V0C5.373 0 0 5.373 0 12h4z"></path>
        </svg>
        {{ loading ? 'Guardando...' : 'Agregar Tarea' }}
      </button>
    </div>
  </div>
</template>

<script setup>
import { ref, computed } from 'vue'
import { useTaskStore } from '../stores/taskStore'

const store = useTaskStore()
const name = ref('')
const description = ref('')
const dueDay = ref('')
const showErrors = ref(false)
const loading = ref(false)

const monthNames = {
  'enero': 1, 'febrero': 2, 'marzo': 3, 'abril': 4,
  'mayo': 5, 'junio': 6, 'julio': 7, 'agosto': 8,
  'septiembre': 9, 'octubre': 10, 'noviembre': 11, 'diciembre': 12
}

const monthNamesDisplay = [
  'Enero', 'Febrero', 'Marzo', 'Abril', 'Mayo', 'Junio',
  'Julio', 'Agosto', 'Septiembre', 'Octubre', 'Noviembre', 'Diciembre'
]

const dueMonthText = ref('')

const parsedMonth = computed(() => {
  const raw = dueMonthText.value.trim().toLowerCase()
  // Try name match
  if (monthNames[raw]) return monthNames[raw]
  // Try partial match
  const match = Object.keys(monthNames).find(m => m.startsWith(raw))
  if (match) return monthNames[match]
  // Try number
  const n = parseInt(raw)
  if (!isNaN(n) && n >= 1 && n <= 12) return n
  return null
})

const resolvedYear = computed(() => {
  const now = new Date()
  if (!dueDay.value || !parsedMonth.value) return now.getFullYear()
  const candidate = new Date(now.getFullYear(), parsedMonth.value - 1, dueDay.value)
  candidate.setHours(0, 0, 0, 0)
  const today = new Date(); today.setHours(0, 0, 0, 0)
  return candidate < today ? now.getFullYear() + 1 : now.getFullYear()
})

const computedDueDate = computed(() => {
  if (!dueDay.value || !parsedMonth.value) return ''
  const m = String(parsedMonth.value).padStart(2, '0')
  const d = String(dueDay.value).padStart(2, '0')
  return `${resolvedYear.value}-${m}-${d}`
})

async function handleSubmit() {
  showErrors.value = true
  if (!name.value.trim() || !description.value.trim() || !computedDueDate.value) return
  loading.value = true
  await store.createTask(name.value.trim(), description.value.trim(), computedDueDate.value)
  loading.value = false
  name.value = ''
  description.value = ''
  dueDay.value = ''
  dueMonthText.value = ''
  showErrors.value = false
}
</script>
