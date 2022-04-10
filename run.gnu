set terminal png
set output "Error.png"
set title "Temps"
set xlabel "Generation"
set ylabel "Error %"
set style data linespoints
plot "data.txt" using 1:3 title "Error" smooth bezier 
set output "Time.png"
set title "Temps"
set xlabel "Generation"
set ylabel "Time"
set style data linespoints
plot "data.txt"  using 1:2 title "Time"  smooth bezier 
set output "Error_bis.png"
set title "Temps"
set xlabel "Generation"
set ylabel "Error %"
set style data linespoints
plot "data_bis.txt" using 1:3 title "Error" smooth bezier 
set output "Time_bis.png"
set title "Temps"
set xlabel "Generation"
set ylabel "Time"
set style data linespoints
plot "data_bis.txt"  using 1:2 title "Time"  smooth bezier 