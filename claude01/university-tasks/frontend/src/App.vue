<template>
  <LoginView v-if="!auth.isAuthenticated" />
  <HomeView v-else />
</template>

<script setup>
import { useAuthStore } from './stores/authStore'
import LoginView from './views/LoginView.vue'
import HomeView from './views/HomeView.vue'

const auth = useAuthStore()
</script>
