package com.quinta;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class FileTransfer {
    private final static int SOC_PORT = 4444;
    private final static String FILE_TO_SEND = "path_to_Archivio.txt";
    String host = "127.0.0.1";
    FileInputStream fis = null;
    BufferedInputStream bis = null;
    OutputStream os = null;
    ServerSocket servsock = null;
    Socket sck = null;

    // Costruttore vuoto

    public FileTransfer() {
    }

    // Funzione che si connette e trasferisce il file in byte[]

    public void transfer() {
            System.out.println("Waiting..");
            try {
                sck = new Socket(host, SOC_PORT);
                System.out.println("Accepted connection :" + sck);
                // Send file
                File myFile = new File(FILE_TO_SEND);
                byte[] array = new byte[(int) myFile.length()];
                fis = new FileInputStream(myFile);
                bis = new BufferedInputStream(fis);
                bis.read(array, 0, array.length);
                os = sck.getOutputStream();
                System.out.println("Sending" + FILE_TO_SEND + "(" + array.length + "bytes )");
                os.write(array, 0, array.length);
                os.flush();
                System.out.println("Done. ");
            } catch (IOException ex) {
                System.out.println(ex.getMessage() + ": An Inbound Connection Was Not Resolved ");
            } finally {
                if (bis != null) {
                    try {
                        bis.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
                if (os != null) {
                    try {
                        os.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
                if (sck != null) {
                    try {
                        sck.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }
            if (servsock != null) {
                try {
                    servsock.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }


