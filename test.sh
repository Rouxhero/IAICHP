ROUGE="\033[31m "
VERT="\033[32m "
NORMAL="\033[0m"
size=500
echo "" > data.txt
echo -e "################ ${VERT}TEST ${NORMAL}##########"
for (( c=0; c<=1600  ; c+=10 ))
do  
    echo -e "Test for n = $c"
    echo -ne "${c}">> data.txt
	./example1 $c >> data.txt
done
echo "" > data_bis.txt
echo -e "################ ${VERT}TEST BIS ${NORMAL}##########"
for (( c=0; c<=150  ; c+=5 ))
do  
    echo -e "Test for n = $c"
    echo -ne "${c}">> data_bis.txt
	./example1_bis $c >> data_bis.txt
done