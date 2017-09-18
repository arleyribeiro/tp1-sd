echo -e "\n### SCRIPT: Iniciando [Servidor:8880]" 
g++ multi-server.cpp -w -lpthread -o server
./server 8880 &
sleep 1


echo -e "\n### SCRIPT: Iniciando [Servidor:8881]" 
./server 8881 &
sleep 1


echo -e "\n###SCRIPT: Criando arquivo com listagem de servidores"
cat > "servidores.txt" << EOF1
127.0.0.1 8880
127.0.0.1 8881
EOF1
sleep 1


echo -e "\n### SCRIPT: Iniciando [Cliente]" 
g++ client.cpp -o client 
./client "servidores.txt" 
sleep 5

echo -e "\n\n					FIM\n\n\n"
chmod +x script-kill.sh
./script-kill.sh