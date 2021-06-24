package com.quinta;

public class Sys {

    // Metodo Nativo per Catturare le info relative al processore
    public static native void getInfo(Sistema s);
    //Metodo Nativo per Catturare l'istante di sistema
    public static native void getTime(Sistema s);
    //Metodo Nativo per recuperare informazioni da Computer System
    public static native void getMb(Sistema s);

}
