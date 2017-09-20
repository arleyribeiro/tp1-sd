PORTA_SERVIDOR_1=8880
PORTA_SERVIDOR_2=8881
PORTA_SERVIDOR_3=8882
PORTA_SERVIDOR_4=8883

echo -e "\n[SCRIPT]: Iniciando [Servidor:$PORTA_SERVIDOR_1]" 
g++ maquina_1/multi-server.cpp -w -lpthread -o maquina_1/server
./maquina_1/server $PORTA_SERVIDOR_1 &
sleep 2

echo -e "\n[SCRIPT]: Iniciando [Servidor:$PORTA_SERVIDOR_2]" 
g++ maquina_2/multi-server.cpp -w -lpthread -o maquina_2/server
./maquina_2/server $PORTA_SERVIDOR_2 &
sleep 2

echo -e "\n[SCRIPT]: Iniciando [Servidor:$PORTA_SERVIDOR_3]" 
g++ maquina_3/multi-server.cpp -w -lpthread -o maquina_3/server
./maquina_3/server $PORTA_SERVIDOR_3 &
sleep 2

echo -e "\n[SCRIPT]: Iniciando [Servidor:$PORTA_SERVIDOR_4]" 
g++ maquina_4/multi-server.cpp -w -lpthread -o maquina_4/server
./maquina_4/server $PORTA_SERVIDOR_4 &
sleep 2

echo -e "\n[SCRIPT]: Criando arquivo com listagem de servidores"
rm -f "servidores.txt"
cat > "servidores.txt" << EOF1
127.0.0.1 $PORTA_SERVIDOR_1
127.0.0.1 $PORTA_SERVIDOR_2
127.0.0.1 $PORTA_SERVIDOR_3
127.0.0.1 $PORTA_SERVIDOR_4
EOF1
sleep 2

echo -e "\n[SCRIPT]: Iniciando [Cliente]" 
g++ maquina_3/client.cpp -o maquina_3/client 
./maquina_3/client "servidores.txt" 'grep "usb_bluetooth" *.log | head -1'
sleep 10

echo -e "\n\n[SCRIPT]:					FIM\n\n\n"
chmod +x script-kill.sh
./script-kill.sh