package com.quinta;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class CheckPorts implements Runnable {
    //Variabili Globali

    //Test porte
    private Socket sock;
    //Socket
    private FileTransfer f;
    //Salva su file
    private PrintWriter pr;
    private FileWriter fw;
    private BufferedWriter bw;
    private File file= new File("path_to_Archivio.txt");

    //Costruttore della classe
    public CheckPorts(){

    }

    //Funzione che si occupa di controllare le porte aperte in base ad uno specifico range
    public void check(){
            try {
                fw = new FileWriter(file, true);
                bw = new BufferedWriter(fw);
                pr = new PrintWriter(bw);
                pr.write("\n\nOpen ports: ");
            } catch (Exception e) {
            }

            for (int i = 2000; i < 2030; i++) {
                try {
                    sock = new Socket("127.0.0.1", i);
                    pr.write("\nPort: "+i+" open");
                    pr.flush();
                    sock.close();
                } catch (IOException e) {
                }
            }
    }


    //Avvio del processo
    @Override
    public void run(){
        check();
    }
}
