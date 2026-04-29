import { defineStore } from 'pinia'

const API_BASE = '/api'

function authHeaders() {
  const token = localStorage.getItem('token')
  return {
    'Content-Type': 'application/json',
    ...(token ? { Authorization: `Bearer ${token}` } : {}),
  }
}

export const useTaskStore = defineStore('tasks', {
  state: () => ({
    tasks: [],
    trash: [],
    loading: false,
    error: null,
    activeSection: 'pending',
  }),

  getters: {
    pendingTasks: (state) => state.tasks.filter((t) => t.status === 'pending'),
    completedTasks: (state) => state.tasks.filter((t) => t.status === 'completed'),
  },

  actions: {
    async fetchTasks() {
      this.loading = true
      this.error = null
      try {
        const [tasksRes, trashRes] = await Promise.all([
          fetch(`${API_BASE}/tasks`, { headers: authHeaders() }),
          fetch(`${API_BASE}/tasks/trash`, { headers: authHeaders() }),
        ])
        if (tasksRes.status === 401 || trashRes.status === 401) {
          this._handleUnauthorized()
          return
        }
        if (!tasksRes.ok) throw new Error('Error al cargar las tareas')
        if (!trashRes.ok) throw new Error('Error al cargar la papelera')
        this.tasks = await tasksRes.json()
        this.trash = await trashRes.json()
      } catch (e) {
        this.error = e.message
      } finally {
        this.loading = false
      }
    },

    async createTask(name, description, dueDate) {
      this.error = null
      try {
        const res = await fetch(`${API_BASE}/tasks`, {
          method: 'POST',
          headers: authHeaders(),
          body: JSON.stringify({ name, description, due_date: dueDate }),
        })
        if (res.status === 401) { this._handleUnauthorized(); return }
        if (!res.ok) throw new Error('Error al crear la tarea')
        await this.fetchTasks()
      } catch (e) {
        this.error = e.message
      }
    },

    async completeTask(id) {
      this.error = null
      try {
        const res = await fetch(`${API_BASE}/tasks/${id}/status`, {
          method: 'PATCH',
          headers: authHeaders(),
          body: JSON.stringify({ status: 'completed' }),
        })
        if (res.status === 401) { this._handleUnauthorized(); return }
        if (!res.ok) throw new Error('Error al actualizar la tarea')
        await this.fetchTasks()
      } catch (e) {
        this.error = e.message
      }
    },

    async setPending(id) {
      this.error = null
      try {
        const res = await fetch(`${API_BASE}/tasks/${id}/status`, {
          method: 'PATCH',
          headers: authHeaders(),
          body: JSON.stringify({ status: 'pending' }),
        })
        if (res.status === 401) { this._handleUnauthorized(); return }
        if (!res.ok) throw new Error('Error al actualizar la tarea')
        await this.fetchTasks()
      } catch (e) {
        this.error = e.message
      }
    },

    async deleteTask(id) {
      this.error = null
      try {
        const res = await fetch(`${API_BASE}/tasks/${id}`, {
          method: 'DELETE',
          headers: authHeaders(),
        })
        if (res.status === 401) { this._handleUnauthorized(); return }
        if (!res.ok) throw new Error('Error al eliminar la tarea')
        await this.fetchTasks()
      } catch (e) {
        this.error = e.message
      }
    },

    async restoreTask(id) {
      this.error = null
      try {
        const res = await fetch(`${API_BASE}/tasks/trash/${id}/restore`, {
          method: 'POST',
          headers: authHeaders(),
        })
        if (res.status === 401) { this._handleUnauthorized(); return }
        if (!res.ok) throw new Error('Error al restaurar la tarea')
        await this.fetchTasks()
      } catch (e) {
        this.error = e.message
      }
    },

    async permanentDelete(id) {
      this.error = null
      try {
        const res = await fetch(`${API_BASE}/tasks/trash/${id}`, {
          method: 'DELETE',
          headers: authHeaders(),
        })
        if (res.status === 401) { this._handleUnauthorized(); return }
        if (!res.ok) throw new Error('Error al eliminar permanentemente')
        await this.fetchTasks()
      } catch (e) {
        this.error = e.message
      }
    },

    async emptyTrash() {
      this.error = null
      try {
        const res = await fetch(`${API_BASE}/tasks/trash`, {
          method: 'DELETE',
          headers: authHeaders(),
        })
        if (res.status === 401) { this._handleUnauthorized(); return }
        if (!res.ok) throw new Error('Error al vaciar la papelera')
        await this.fetchTasks()
      } catch (e) {
        this.error = e.message
      }
    },

    setActiveSection(section) {
      this.activeSection = section
    },

    _handleUnauthorized() {
      localStorage.removeItem('token')
      localStorage.removeItem('userEmail')
      window.location.reload()
    },
  },
})
