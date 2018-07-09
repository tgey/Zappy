echo "Argument OK"
./zappy_server -p 4242 -x 4 -y 8 -n name1 name2 -c 2 -f 100 >> res ; echo $?

echo "Argument manque un flag"
./zappy_server -p 4242 -x 4 -y 8 -n name1 name2 -c 2 >> res ; echo $?

echo "Argument manque un flag 2"
./zappy_server -p 4242 -x 4 -y 8 -n name1 name2 -c 2 -f >> res ; echo $?

echo "Argument manque un flag 3"
./zappy_server -p 4242 -x 4 -y 8 -n -c 2 -f >> res ; echo $?

echo "Argument flag existe pas"
./zappy_server -p 4242 -x 4 -a 8 -n ppp -c 2 -f 100 >> res ; echo $?

echo "Argument flag existe pas"
./zappy_server -p 4242 -x 4 -a 8 -n yolo test -c 2 -f 100 >> res ; echo $?

echo "Argument flag double"
./zappy_server -p 4242 -x 8 -x 4 -a 8 -n yolo test -c 2 -f 100 >> res ; echo $?

echo "Argument trop de flag"
./zappy_server -p 4242 -x 4 -y 8 -n name1 name2 -c 2 -f 100 -a 89 >> res ; echo $?

echo "Argument trop de val"
./zappy_server -p 4242 -x 4 99 -y 8 -n name1 name2 -c 2 -f 100 >> res ; echo $?

rm res;
