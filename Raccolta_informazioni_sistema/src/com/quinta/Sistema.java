package com.quinta;

public class Sistema {

    // Variabili Globali
    //Processore
    private int ProcessorArchitecture;
    private int NumberOfProcessor;
    private int ProcessorLevel;
    private long ProcessorRevision;
    private String procArch="";
    //Istante della Macchina
    private int sisYear;
    private int sisMonth;
    private int sisDay;
    private int sisHour;
    private int sisMinute;
    private int sisSecond;
    private String completeTime="";
    //Computer_System caratteristiche
    private String mbManufacturer="";
    private String mbModel="";
    private String mbName="";
    private String mbDescription="";
    private String mbDNSHostName="";
    private String mbDomain="";
    private String mbStatus="";
    private String mbSystemType="";
    private String mbUserName="";
    private int mbAdminPasswordStatus=0;
    private String mbSystemFamily="";
    private String mbSystemSKUNumber="";
    private String mbTotalPhysicalMemory="";
    //Base_Board caratteristiche
    private String bbSerialNumber="";
    //Operating System caratteristiche
    private String osBootDevice="";
    private String osBuildNumber="";
    private String osBuildType="";
    private String osCodeSet="";
    private String osCountryCode="";
    private String osSystemDirectory="";
    private String osSystemDevice="";
    private String osSystemDrive="";
    private String osWindowsDirectory="";
    //BIOS caratteristiche
    private String bsSerialNumber="";
    private String bsSMBIOSBIOSVersion="";
    private String bsSoftwareElementID="";
    private String bsStatus="";
    //Net Adapter caratteristiche
    private String naDeviceID="";
    private String naPNPDeviceID="";
    private String naName="";
    private String naStatusInfo="";
    private String naSpeed="";
    private String naPortType="";
    private String naPermanentAddress="";
    private String naInterfaceDescription="";
    private String naInterfaceName="";
    private String naInterfaceIndex="";
    private String naDeviceName="";
    private String naVlanID="";
    private String naDriverDate="";
    private String naDriverVersionString="";
    private String naDriverName="";
    private String naDriverDescription="";
    private String naDriverProvider="";
    private String naComponentID="";
    private String naAvailability="";
    //Net Adapter Configuration caratteristiche


    //Costruttore
    public Sistema(){

    }

    //Gettter & Setter per "ProcessorArchitecture"
    public int getProcessorArchitecture() {
        return ProcessorArchitecture;
    }
    public void setProcessorArchitecture(int processorArchitecture) {
        ProcessorArchitecture = processorArchitecture;
    }

    //Gettter & Setter per "NumberOfProcessor"
    public int getNumberOfProcessor() {
        return NumberOfProcessor;
    }
    public void setNumberOfProcessor(int numberOfProcessor) {
        NumberOfProcessor = numberOfProcessor;
    }

    //Gettter & Setter per "ProcessorLevel"
    public int getProcessorLevel() {
        return ProcessorLevel;
    }
    public void setProcessorLevel(int processorLevel) {
        ProcessorLevel = processorLevel;
    }

    //Gettter & Setter per "ProcessorRevision"
    public long getProcessorRevision() {
        return ProcessorRevision;
    }
    public void setProcessorRevision(long processorRevision) {
        ProcessorRevision = processorRevision;
    }

    //Getter per "ProcArch"
    public String getProcArch() {
        return procArch;
    }

    //Restituisce la "ProcessorArchitecture" in linguaggio naturale in "prochArch"
    public void friendlyArch(){
        if (ProcessorArchitecture==9){
            procArch="x64 (AMD or Intel)";
        }else if(ProcessorArchitecture==5){
            procArch="ARM";
        }else if(ProcessorArchitecture==12){
            procArch="ARM64";
        }else if(ProcessorArchitecture==6){
            procArch="Intel Itanium-based";
        }else if(ProcessorArchitecture==0){
            procArch="x86";
        }else{
            procArch="Unknown architecture.";
        }
    }

    //Setter per "SisYear"
    public void setSisYear(int sisYear) {
        this.sisYear = sisYear;
    }

    //Setter per "SisMonth"
    public void setSisMonth(int sisMonth) {
        this.sisMonth = sisMonth;
    }

    //Setter per "SisDay"
    public void setSisDay(int sisDay) {
        this.sisDay = sisDay;
    }

    //Setter per "SisHour"
    public void setSisHour(int sisHour) {
        this.sisHour = sisHour;
    }

    //Setter per "SisMinute"
    public void setSisMinute(int sisMinute) {
        this.sisMinute = sisMinute;
    }

    //Setter per "SisSecond"
    public void setSisSecond(int sisSecond) {
        this.sisSecond = sisSecond;
    }

    //Getter per "CompleteTime"
    public String getCompleteTime() {
        return completeTime;
    }

    //Funzione che imposta la data in modalità friendly
    public void FriendlyTime(){
        completeTime=completeTime+String.valueOf(sisYear)+"/";
        completeTime=completeTime+String.valueOf(sisMonth)+"/";
        completeTime=completeTime+String.valueOf(sisDay)+" ";
        completeTime=completeTime+String.valueOf(sisHour+1)+":";
        completeTime=completeTime+String.valueOf(sisMinute)+":";
        completeTime=completeTime+String.valueOf(sisSecond)+"\n";
    }

    //Setter per "mbManufacturer"
    public void setMbManufacturer(String mbManufacturer) {
        this.mbManufacturer = mbManufacturer;
    }

    //Setter per "mbModel"
    public void setMbModel(String mbModel) {
        this.mbModel = mbModel;
    }

    //Setter per "mbName"
    public void setMbName(String mbName) {
        this.mbName = mbName;
    }

    //Setter per "mbDescription"
    public void setMbDescription(String mbDescription) {
        this.mbDescription = mbDescription;
    }

    //Setter per "mbDNSHostName"
    public void setMbDNSHostName(String mbDNSHostName) {
        this.mbDNSHostName = mbDNSHostName;
    }

    //Setter per "mbDomain"
    public void setMbDomain(String mbDomain) {
        this.mbDomain = mbDomain;
    }

    //Setter per "mbStatus"
    public void setMbStatus(String mbStatus) {
        this.mbStatus = mbStatus;
    }

    //Setter per "mbSystemType"
    public void setMbSystemType(String mbSystemType) {
        this.mbSystemType = mbSystemType;
    }

    //Setter per "mbUserName"
    public void setMbUserName(String mbUserName) {
        this.mbUserName = mbUserName;
    }

    //Setter per "mbAdminPasswordStatus"
    public void setMbAdminPasswordStatus(int mbAdminPasswordStatus) {
        this.mbAdminPasswordStatus = mbAdminPasswordStatus;
    }

    //Setter per "mbSystemFamily"
    public void setMbSystemFamily(String mbSystemFamily) {
        this.mbSystemFamily = mbSystemFamily;
    }

    //Setter per "mbSystemSKUNumber"
    public void setMbSystemSKUNumber(String mbSystemSKUNumber) {
        this.mbSystemSKUNumber = mbSystemSKUNumber;
    }

    public void setMbTotalPhysicalMemory(String mbTotalPhysicalMemory) {
        this.mbTotalPhysicalMemory = mbTotalPhysicalMemory;
    }

    //Get info mb tagged toghether
    public String getMbInformation(){
        return "\nManufacturer: "+mbManufacturer+"\nModel: "+mbModel+"\nName: "+mbName+"\nDNS Host Name: "+mbDNSHostName+
                "\nDomain: "+mbDomain+"\nStatus : "+mbStatus+"\nSystem Type: "+mbSystemType+"\nUser Name: "+mbUserName+
                "\nDescription: "+mbDescription+"\nAdminPasswordStatus: "+mbAdminPasswordStatus+"\nSystem Family: "+mbSystemFamily+
                "\nSystem SKUNumber: "+mbSystemSKUNumber+"\nTotal Physical Memory: "+mbTotalPhysicalMemory;
    }

    //Setter per "bbSerialNumber"
    public void setBbSerialNumber(String bbSerialNumber) {
        this.bbSerialNumber = bbSerialNumber;
    }

    //Setter per "osBootDevice"
    public void setOsBootDevice(String osBootDevice) {
        this.osBootDevice = osBootDevice;
    }

    //Setter per "osBuildNumber"
    public void setOsBuildNumber(String osBuildNumber) {
        this.osBuildNumber = osBuildNumber;
    }

    //Setter per "osBuildType"
    public void setOsBuildType(String osBuildType) {
        this.osBuildType = osBuildType;
    }

    //Setter per "osCodeSet"
    public void setOsCodeSet(String osCodeSet) {
        this.osCodeSet = osCodeSet;
    }

    //Setter per "osCountryCode"
    public void setOsCountryCode(String osCountryCode) {
        this.osCountryCode = osCountryCode;
    }

    //Setter per "osSystemDirectory"
    public void setOsSystemDirectory(String osSystemDirectory) {
        this.osSystemDirectory = osSystemDirectory;
    }

    //Setter per "osSystemDevice"
    public void setOsSystemDevice(String osSystemDevice) {
        this.osSystemDevice = osSystemDevice;
    }

    //Setter per "osSystemDrive"
    public void setOsSystemDrive(String osSystemDrive) {
        this.osSystemDrive = osSystemDrive;
    }

    //Setter per "osWindowsDirectory"
    public void setOsWindowsDirectory(String osWindowsDirectory) {
        this.osWindowsDirectory = osWindowsDirectory;
    }

    //Get info os tagged toghether
    public String getBbInformation(){
        return "\nSerial Number: "+bbSerialNumber+"\nBoot Device: "+osBootDevice+"\nBuild Number: "+osBuildNumber+
                "\nBuild Type: "+osBuildType+"\nCodeSet: "+osCodeSet+"\nCountry Code: "+osCountryCode+"\nSystem Directory: "+osSystemDirectory+
                "\nSystem Device: "+osSystemDevice+"\nSystem Drive: "+osSystemDrive+"\nWindows Directory: "+osWindowsDirectory;
    }

    //Setter per "bsSerialNumber"
    public void setBsSerialNumber(String bsSerialNumber) {
        this.bsSerialNumber = bsSerialNumber;
    }

    //Setter per "bsSMBIOSBIOSVersion"
    public void setBsSMBIOSBIOSVersion(String bsSMBIOSBIOSVersion) {
        this.bsSMBIOSBIOSVersion = bsSMBIOSBIOSVersion;
    }

    //Setter per "bsSoftwareElementID"
    public void setBsSoftwareElementID(String bsSoftwareElementID) {
        this.bsSoftwareElementID = bsSoftwareElementID;
    }

    //Setter per "bsStatus"
    public void setBsStatus(String bsStatus) {
        this.bsStatus = bsStatus;
    }

    //Get info bs tagged toghether
    public String getBsInformation(){
        return "\nSerial Number: "+bsSerialNumber+"\nSMBIOSBIOSVersion: "+bsSMBIOSBIOSVersion+"\nSoftwareElementID: "+bsSoftwareElementID+"\nStatus: "+bsStatus;
    }

    //Setter per "naDeviceID"
    public void setNaDeviceID(String naDeviceID) {
        this.naDeviceID = naDeviceID;
    }

    //Setter per "naPNPDeviceID"
    public void setNaPNPDeviceID(String naPNPDeviceID) {
        this.naPNPDeviceID = naPNPDeviceID;
    }

    //Setter per "naName"
    public void setNaName(String naName) {
        this.naName = naName;
    }

    //Setter per "naStatusInfo"
    public void setNaStatusInfo(String naStatusInfo) {
        this.naStatusInfo = naStatusInfo;
    }

    //Setter per "naSpeed"
    public void setNaSpeed(String naSpeed) {
        this.naSpeed = naSpeed;
    }

    //Setter per "naPortType"
    public void setNaPortType(String naPortType) {
        this.naPortType = naPortType;
    }

    //Setter per "naPermanentAddress"
    public void setNaPermanentAddress(String naPermanentAddress) {
        this.naPermanentAddress = naPermanentAddress;
    }

    //Setter per "naInterfaceDescription"
    public void setNaInterfaceDescription(String naInterfaceDescription) {
        this.naInterfaceDescription = naInterfaceDescription;
    }

    //Setter per "naInterfaceName"
    public void setNaInterfaceName(String naInterfaceName) {
        this.naInterfaceName = naInterfaceName;
    }

    //Setter per "naInterfaceIndex"
    public void setNaInterfaceIndex(String naInterfaceIndex) {
        this.naInterfaceIndex = naInterfaceIndex;
    }

    //Setter per "naDeviceName"
    public void setNaDeviceName(String naDeviceName) {
        this.naDeviceName = naDeviceName;
    }

    //Setter per "naVlanID"
    public void setNaVlanID(String naVlanID) {
        this.naVlanID = naVlanID;
    }

    //Setter per "naDriverDate"
    public void setNaDriverDate(String naDriverDate) {
        this.naDriverDate = naDriverDate;
    }

    //Setter per "naDriverVersionString"
    public void setNaDriverVersionString(String naDriverVersionString) {
        this.naDriverVersionString = naDriverVersionString;
    }

    //Setter per "naDriverName"
    public void setNaDriverName(String naDriverName) {
        this.naDriverName = naDriverName;
    }

    //Setter per "naDriverDescription"
    public void setNaDriverDescription(String naDriverDescription) {
        this.naDriverDescription = naDriverDescription;
    }

    //Setter per "naDriverProvider"
    public void setNaDriverProvider(String naDriverProvider) {
        this.naDriverProvider = naDriverProvider;
    }

    //Setter per "naComponentID"
    public void setNaComponentID(String naComponentID) {
        this.naComponentID = naComponentID;
    }

    //Setter per "naAvailability"
    public void setNaAvailability(String naAvailability) {
        this.naAvailability = naAvailability;
    }

    //Get info na tagged toghether
    public String getNaInformation(){
        return "\nDeviceID: "+naDeviceID+"\nPNPDeviceID: "+naPNPDeviceID+"\nName: "+naName+"\nStatus Info: "+naStatusInfo
                +"\nBandwith: "+naSpeed+" bits"+"\nPort Type: "+naPortType+"\nPermanent Address: "+naPermanentAddress
                +"\nInterface Description: "+naInterfaceDescription+"\nInterface Name: "+naInterfaceName
                +"\nInterface Index: "+naInterfaceIndex+"\nDevice Name: "+naDeviceName+"\nVlan ID: "+naVlanID
                +"\nDriver Date: "+naDriverDate+"\nDriver Version: "+naDriverVersionString+"\nDriver Name: "+naDriverName
                +"\nDriver Description: "+naDriverDescription+"\nDriver Provider: "+naDriverProvider+"\nComponent ID: "+naComponentID
                +"\nAvailability: "+naAvailability;
    }
}
