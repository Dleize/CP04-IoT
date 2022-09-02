# CP04-IoT

Nome dos alunos: João Victor Deziderio Chinelato /
                 Nathan Pagliari Augusto

Turma: 2TDSF

Ano: 2022

## Objetivo / descrição do Projeto
Para atender esta rubrica, o sistema deve ser capaz de coletar a identificação da TAG RFID com o Arduino (ARDUINO1) e envia utilizando formato JSON para um fluxo Node-Red que realiza duas funções: - publica em um tópico utilizando o protocolo MQTT ; - Notifica o usuário via telegram. Um segundo fluxo Node-Red subscreve o tópico e exibe o valor da TAG em um DASHBOARD.
<img src="https://user-images.githubusercontent.com/30454929/188241495-cc50dc58-2030-494b-975c-ce88c6d1db50.png" width="550">


## Node-RED

<img src="https://user-images.githubusercontent.com/30454929/188241159-83f01384-144e-4ef7-aee9-90dd0a8c396e.JPG" width="550">


## Como usar 
1 - Iniciar node-red através de um prompt de comando.
2 - Deve ser utilizado Node-red e instalar os nodes:
      node-red-contrib-telegrambot
      node-red-contrib-telegrambot-home
      node-red-node-email
      node-red-node-serialport
3 - Importe o arquivo JSON.
4 - Abra o link (http://127.0.0.1:1880/ui/), para controlar o servo motor.
5 - Montar o hardware.
6 - Importar o arquivo arduino.
  
## Videos  
[Video 1](https://www.youtube.com/shorts/gDbCFbe4WN4)
[Video 2](https://www.youtube.com/watch?v=ypJAlW528sw)
