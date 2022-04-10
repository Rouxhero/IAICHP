ROUGE="\033[31m "
VERT="\033[32m "
NORMAL="\033[0m"
size=500
# echo "" > data.txt
# echo -e "################ ${VERT}TEST ${NORMAL}##########"
# for (( c=0; c<=1600  ; c+=10 ))
# do  
#     echo -e "Test for n = $c"
#     echo -ne "${c}">> data.txt
# 	./example1 $c >> data.txt
# done
echo "" > res_bis.dat
echo -e "################ ${VERT}TEST BIS ${NORMAL}##########"
for (( c=0; c<=1000  ; c+=50 ))
do  
    echo -e "Test for n = $c"
    echo -ne "${c}">> res_bis.dat
	./example1_bis $c >> res_bis.dat
done
echo "" > res_double.dat
for (( c=0; c<=1000  ; c+=50))
do  
    echo -e "Test for n = $c"
    echo -ne "${c}">> res_double.dat
	./example1_double $c >> res_double.dat
done
echo "" > res_double_par.dat
for (( c=0; c<=1000  ; c+=50))
do  
    echo -e "Test for n = $c"
    echo -ne "${c}">> res_double_par.dat
	./example1_double_par $c >> res_double_par.dat
done