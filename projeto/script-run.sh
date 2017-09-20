PORTA_SERVIDOR_1=8880
PORTA_SERVIDOR_2=8881

echo -e "\n[SCRIPT]: Iniciando [Servidor:$PORTA_SERVIDOR_1]" 
g++ multi-server.cpp -w -lpthread -o server
./server $PORTA_SERVIDOR_1 &
sleep 2

echo -e "\n[SCRIPT]: Iniciando [Servidor:$PORTA_SERVIDOR_2]" 
./server $PORTA_SERVIDOR_2 &
sleep 2

echo -e "\n[SCRIPT]: Criando arquivo com listagem de servidores"
rm -f "servidores.txt"
cat > "servidores.txt" << EOF1
127.0.0.1 $PORTA_SERVIDOR_1
127.0.0.1 $PORTA_SERVIDOR_2
EOF1
sleep 2

echo -e "\n[SCRIPT]: Iniciando [Cliente]" 
g++ client.cpp -o client 
./client "servidores.txt" 'grep "usb_bluetooth" log.log | head -1'
sleep 10

echo -e "\n\n[SCRIPT]:					FIM\n\n\n"
chmod +x script-kill.sh
./script-kill.sh