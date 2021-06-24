package com.quinta;

public class Main {
    //Caricamento DLL
    static{
        System.load("path_to_Sysinfo.dll");
    }

    public static void main(String[] args) {
        Sistema sistema = new Sistema();
        //Cattura le info del processore
        Sys.getInfo(sistema);
        //Pone Architettura friendly-user
        sistema.friendlyArch();
        //Stampa le info relative al processore
        System.out.println("Proc Ark: "+sistema.getProcArch()+"\nProc Level: "+sistema.getProcessorLevel()+"\nProc Rev: "+sistema.getProcessorRevision()+"\nEnum Proc: "+sistema.getNumberOfProcessor());
        //Cattura l'istante di sistema
        Sys.getTime(sistema);
        //Prepara l'istante friendly-user
        sistema.FriendlyTime();
        //Stampa l'istante
        System.out.println(sistema.getCompleteTime());
        //Recupera produttore e modello
        Sys.getMb(sistema);
        //Stampa
        System.out.println(sistema.getMbInformation());
        System.out.println(sistema.getBbInformation());
        System.out.println(sistema.getBsInformation());
        System.out.println(sistema.getNaInformation());

    }
}
