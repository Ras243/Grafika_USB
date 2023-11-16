
import turtle

# Membuat jendela gambar
window = turtle.Screen()
window.title("Menggambar Persegi Kotak")

# Membuat objek turtle
kotak = turtle.Turtle()

# Menggambar persegi kotak
for _ in range(4):
    kotak.forward(100)  # Panjang sisi
    kotak.right(90)     # Sudut putaran

# Menutup jendela saat diklik
window.exitonclick()
