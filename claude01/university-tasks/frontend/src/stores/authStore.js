import { defineStore } from 'pinia'

const API_BASE = '/api'

export const useAuthStore = defineStore('auth', {
  state: () => ({
    token: localStorage.getItem('token') || null,
    userEmail: localStorage.getItem('userEmail') || null,
  }),

  getters: {
    isAuthenticated: (state) => !!state.token,
  },

  actions: {
    async login(email, password) {
      const res = await fetch(`${API_BASE}/auth/login`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ email, password }),
      })
      if (!res.ok) {
        const data = await res.json().catch(() => ({}))
        throw new Error(data.detail || 'Error al iniciar sesión')
      }
      const data = await res.json()
      this.token = data.access_token
      this.userEmail = email
      localStorage.setItem('token', data.access_token)
      localStorage.setItem('userEmail', email)
    },

    async register(email, password) {
      const res = await fetch(`${API_BASE}/auth/register`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ email, password }),
      })
      if (!res.ok) {
        const data = await res.json().catch(() => ({}))
        throw new Error(data.detail || 'Error al registrarse')
      }
      await this.login(email, password)
    },

    logout() {
      this.token = null
      this.userEmail = null
      localStorage.removeItem('token')
      localStorage.removeItem('userEmail')
    },
  },
})
