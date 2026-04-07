/** @type {import('tailwindcss').Config} */
export default {
  content: ['./src/**/*.{vue,js}', './index.html'],
  theme: {
    extend: {
      colors: {
        navy: {
          DEFAULT: '#1e2d4a',
          light: '#2a3f6b',
          dark: '#131d31',
        },
      },
      fontFamily: {
        sans: ['"DM Sans"', 'sans-serif'],
        heading: ['"Playfair Display"', 'serif'],
      },
    },
  },
  plugins: [],
}
