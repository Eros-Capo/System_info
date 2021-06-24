#include<windows.h>
#include<jni.h>
#include "com_quinta_Sys.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Sysinfoapi.h>
#include<comdef.h>
#include<atlstr.h>
#include<Wbemidl.h>
#include<comutil.h>
#include<iostream>
#include<atlcomcli.h>
#include <wbemcli.h>

#define _WIN32_DCOM
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "wbemuuid.lib")

JNIEXPORT void JNICALL Java_com_quinta_Sys_getInfo(JNIEnv *env,jclass thisClass, jobject thisObj) {
	//Catture le informazioni relative al processore
	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);

	// Trova il riferimento alla classe com.quinta.Sistema
	jclass cls = env->FindClass("com/quinta/Sistema");

	/*--------------------------------------------------------------------------------------------------------------*/
	
	// Trova l'IDmetodo del metodo "setProcessorArchitecture", che prende int come argomento e ritorna void
	jmethodID changeArc = env->GetMethodID(cls, "setProcessorArchitecture", "(I)V");
	if (NULL == changeArc) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setProcessorArchitecture"
	jint architettura = sysInfo.wProcessorArchitecture;
	env->CallVoidMethod(thisObj, changeArc, architettura);

	// Trova l'IDmetodo del metodo "setNumberOfProcessor", che prende Int come argomento e ritorna void
	jmethodID changeNop = env->GetMethodID(cls, "setNumberOfProcessor", "(I)V");
	if (NULL == changeNop) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setNumberOfProcessor"
	jint nProc = sysInfo.dwNumberOfProcessors;
	env->CallVoidMethod(thisObj, changeNop, nProc);

	// Trova l'IDmetodo del metodo "setProcessorLevel", che prende Int come argomento e ritorna void
	jmethodID changePl = env->GetMethodID(cls, "setProcessorLevel", "(I)V");
	if (NULL == changePl) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setProcessorLevel"
	jint procLvl = sysInfo.wProcessorLevel;
	env->CallVoidMethod(thisObj, changePl, procLvl);

	// Trova l'IDmetodo del metodo "setProcessorRevision", che prende Long come argomento e ritorna void
	jmethodID changePr = env->GetMethodID(cls, "setProcessorRevision", "(J)V");
	if (NULL == changePr) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setProcessorRevision"
	jlong procRev = sysInfo.wProcessorRevision;
	env->CallVoidMethod(thisObj, changePr, procRev);

}

JNIEXPORT void JNICALL Java_com_quinta_Sys_getTime(JNIEnv *env, jclass thisClass, jobject thisObj) {
	//Cattura l'ora del sistema
	SYSTEMTIME sysTime;
	GetSystemTime(&sysTime);

	// Trova il riferimento alla classe com.quinta.Sistema
	jclass cls = env->FindClass("com/quinta/Sistema");

	/*--------------------------------------------------------------------------------------------------------------*/

	// Trova l'IDmetodo del metodo "setSisYear", che prende int come argomento e ritorna void
	jmethodID changeYear = env->GetMethodID(cls, "setSisYear", "(I)V");
	if (NULL == changeYear) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setSisYear"
	jint year = sysTime.wYear;
	env->CallVoidMethod(thisObj, changeYear, year);

	// Trova l'IDmetodo del metodo "setSisMonth", che prende int come argomento e ritorna void
	jmethodID changeMonth = env->GetMethodID(cls, "setSisMonth", "(I)V");
	if (NULL == changeMonth) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setSisMonth"
	jint month = sysTime.wMonth;
	env->CallVoidMethod(thisObj, changeMonth, month);

	// Trova l'IDmetodo del metodo "setSisDay", che prende int come argomento e ritorna void
	jmethodID changeDay = env->GetMethodID(cls, "setSisDay", "(I)V");
	if (NULL == changeDay) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setSisDay"
	jint day = sysTime.wDay;
	env->CallVoidMethod(thisObj, changeDay, day);

	// Trova l'IDmetodo del metodo "setSisHour", che prende int come argomento e ritorna void
	jmethodID changeHour = env->GetMethodID(cls, "setSisHour", "(I)V");
	if (NULL == changeHour) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setSisHour"
	jint hour = sysTime.wHour;
	env->CallVoidMethod(thisObj, changeHour, hour);

	// Trova l'IDmetodo del metodo "setSisMinute", che prende int come argomento e ritorna void
	jmethodID changeMinute = env->GetMethodID(cls, "setSisMinute", "(I)V");
	if (NULL == changeMinute) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setSisMinute"
	jint minute = sysTime.wMinute;
	env->CallVoidMethod(thisObj, changeMinute, minute);

	// Trova l'IDmetodo del metodo "setSisSecond", che prende int come argomento e ritorna void
	jmethodID changeSecond = env->GetMethodID(cls, "setSisSecond", "(I)V");
	if (NULL == changeSecond) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setSisSecond"
	jint second = sysTime.wSecond;
	env->CallVoidMethod(thisObj, changeSecond, second);
}

JNIEXPORT void JNICALL Java_com_quinta_Sys_getMb(JNIEnv * env, jclass thisClass, jobject thisObj) {
	//Inzializza DCOM
	HRESULT inizio;
	inizio = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	
	//Stampa l'errore in caso l'inizializzazione fallisca
	if (FAILED(inizio))
	{
		std::cout << "Failed to initialize object. Err code = 0x"
			<< std::hex << inizio << std::endl;
		CoUninitialize();
		return;     // Program has failed.
	}

	//Setta la sicurezza DCOM
	HRESULT sec = NULL;
	sec = CoInitializeSecurity(NULL,                       // security descriptor
		-1,                          // use this simple setting
		NULL,                        // use this simple setting
		NULL,                        // reserved
		RPC_C_AUTHN_LEVEL_DEFAULT,   // authentication level  
		RPC_C_IMP_LEVEL_IMPERSONATE, // impersonation level
		NULL,                        // use this simple setting
		EOAC_NONE,                   // no special capabilities
		NULL);

	//Controllo errori sull'inizializzazione della sicureza DCOM
	if (FAILED(sec))
	{
		std::cout << "Failed to setting security. Err code = 0x"
			<< std::hex << sec << std::endl;
		CoUninitialize();
		return;     // Program has failed.
	}

	//Creazione puntatore ai servizi WMI
	CComPtr< IWbemLocator > locator;
	HRESULT puntatore;
	puntatore = CoCreateInstance(CLSID_WbemAdministrativeLocator, NULL, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID *)&locator);

	//Controllo errori sulla creazione del puntatore ai servizi WMI
	if (FAILED(puntatore))
	{
		std::cout << "Failed to create pointer to WMI services. Err code = 0x"
			<< std::hex << puntatore << std::endl;
		CoUninitialize();
		return;     // Program has failed.
	}

	//Connessione alla LOCAL MACHINE
	CComPtr< IWbemServices > service;
	HRESULT servizio;
	servizio = locator->ConnectServer(L"root\\cimv2", NULL, NULL, NULL, WBEM_FLAG_CONNECT_USE_MAX_WAIT, NULL, NULL, &service);

	//Controllo errori sulla connessione alla LOCAL MACHINE
	if (FAILED(servizio))
	{
		std::cout << "Could not connect. Error code = 0x"
			<< std::hex << servizio << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}


	//QUERY AT Win32_ComputerSystem PROVIDER
	CComPtr< IEnumWbemClassObject > enumerator;
	HRESULT query;
	query = service->ExecQuery(L"WQL", L"SELECT * FROM Win32_ComputerSystem", WBEM_FLAG_FORWARD_ONLY, NULL, &enumerator);

	//Controllo errori sulla query
	if (FAILED(query))
	{
		std::cout << "Query as failed. Error code = 0x"
			<< std::hex << query << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//Lettura della query
	ULONG returnedVal;
	CComPtr< IWbemClassObject > motherboard;
	HRESULT reading;
	reading = enumerator->Next(WBEM_INFINITE,1L, &motherboard, &returnedVal);
	
	//Controllo sulla creazione della struttura ospitante dei dati raccolti tramite la query
	if (FAILED(reading))
	{
		std::cout << "Could not read query. Error code = 0x"
			<< std::hex << reading << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//Raccolta propietà MANUFACTURER
	_variant_t var_man;
	HRESULT taking;
	
	taking = motherboard->Get(L"Manufacturer", 0, &var_man, NULL, NULL);

	//Controllo errori sul recupero della propietà MANUFACTURER
	if (FAILED(taking))
	{
		std::cout << "Could retrive Manufacturer. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->> MANUFACTURER e rilascio
	std::string varfacture = (const char*)_bstr_t(V_BSTR(&var_man));
	const char * var_Manufacture = varfacture.c_str();
	VariantClear(&var_man);

	//Raccolta propietà MODEL
	_variant_t var_Model;
	HRESULT takingDue;

	takingDue = motherboard->Get(L"Model", 0, &var_Model, NULL, NULL);

	//Controllo errori sul recupero della propietà MODEL
	if (FAILED(takingDue))
	{
		std::cout << "Could not retrive Model. Error code = 0x"
			<< std::hex << takingDue << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->> MODEL E RILASCIO
	std::string varMode = (const char*)_bstr_t(V_BSTR(&var_Model));
	const char * varModel = varMode.c_str();
	VariantClear(&var_Model);

	//Raccolta propietà NAME
	_variant_t var_Name;
	HRESULT takingTre;

	takingTre = motherboard->Get(L"Name", 0, &var_Name, NULL, NULL);

	//Controllo errori sul recupero della propietà NAME
	if (FAILED(takingTre))
	{
		std::cout << "Could not retrive Name. Error code = 0x"
			<< std::hex << takingTre << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->> NAME e rilascio
	std::string varNome = (const char*)_bstr_t(V_BSTR(&var_Name));
	const char * varName = varNome.c_str();
	VariantClear(&var_Name);
	
	//Raccolta propietà DESCRIPTION
	_variant_t var_Description;
	HRESULT takingNove;

	takingNove = motherboard->Get(L"Description", 0, &var_Description, NULL, NULL);
	
	//Controllo errori sul recupero della propietà DESCRIPTION
	if (FAILED(takingNove))
	{
		std::cout << "Could not retrive Description. Error code = 0x"
			<< std::hex << takingNove << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->> DESCRIPTION e rilascio
	std::string varDesc = (const char*)_bstr_t(V_BSTR(&var_Description));
	const char * varDescription = varDesc.c_str();
	VariantClear(&var_Description);
	
	
	//Raccolta propietà DNS HOST NAME
	_variant_t var_DNSHostName;
	HRESULT takingQuattro;

	takingQuattro = motherboard->Get(L"DNSHostName", 0, &var_DNSHostName, NULL, NULL);

	//Controllo errori sul recupero della propietà DNS HOST NAME
	if (FAILED(takingQuattro))
	{
		std::cout << "Could not retrive Dns Host Name. Error code = 0x"
			<< std::hex << takingQuattro << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->> DNS HOST NAME e rilascio
	std::string varDNSHostNome = (const char*)_bstr_t(V_BSTR(&var_DNSHostName));
	const char * varDNSHostName = varDNSHostNome.c_str();
	VariantClear(&var_DNSHostName);

	//Raccolta proprietà DOMAIN
	_variant_t var_Domain;
	HRESULT takingCinque;

	takingCinque = motherboard->Get(L"Domain", 0, &var_Domain, NULL, NULL);
	
	//Controllo errori sul recupero della propietà DOMAIN
	if (FAILED(takingCinque))
	{
		std::cout << "Could not retrive Domain. Error code = 0x"
			<< std::hex << takingCinque << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->> DOMAIN e rilascio
	std::string varDominio = (const char*)_bstr_t(V_BSTR(&var_Domain));
	const char * varDomain = varDominio.c_str();
	
	//Raccolta proprietà STATUS
	_variant_t var_Status;
	HRESULT takingSei;

	takingSei = motherboard->Get(L"Status", 0, &var_Status, NULL, NULL);

	//Controllo errori sul recupero della propietà STATUS
	if (FAILED(takingSei))
	{
		std::cout << "Could not retrive Status. Error code = 0x"
			<< std::hex << takingSei << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->> Status e rilascio
	std::string varStat = (const char*)_bstr_t(V_BSTR(&var_Status));
	const char * varStatus = varStat.c_str();

	//Raccolta proprietà SYSTEMTYPE
	_variant_t var_SystemType;
	HRESULT takingSette;

	takingSette = motherboard->Get(L"SystemType", 0, &var_SystemType, NULL, NULL);
	
	//Controllo errori sul recupero della propietà SYSTEMTYPE
	if (FAILED(takingSette))
	{
		std::cout << "Could not retrive System Type. Error code = 0x"
			<< std::hex << takingSette << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}
	//CONVERSIONE VARIANT --->> SystemType e rilascio
	std::string varSystemTy = (const char*)_bstr_t(V_BSTR(&var_SystemType));
	const char * varSystemType = varSystemTy.c_str();
	
	//Raccolta proprietà USERNAME
	_variant_t var_UserName;
	HRESULT takingOtto;

	takingOtto = motherboard->Get(L"UserName", 0, &var_UserName, NULL, NULL);
	
	//Controllo errori sul recupero della propietà USERNAME
	if (FAILED(takingOtto))
	{
		std::cout << "Could not retrive User Name. Error code = 0x"
			<< std::hex << takingOtto << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->> UserName e rilascio
	std::string varUserNome = (const char*)_bstr_t(V_BSTR(&var_UserName));
	const char * varUserName = varUserNome.c_str();
	
	//Raccolta proprietà ADMINPASSWORDSTATUS
	_variant_t var_AdminPasswordStatus;
	HRESULT takingDieci;

	takingDieci = motherboard->Get(L"AdminPasswordStatus", 0, &var_AdminPasswordStatus, NULL, NULL);

	//Controllo errori sul recupero della propietà ADMINPASSWORDSTATUS
	if (FAILED(takingDieci))
	{
		std::cout << "Could not retrive Admin Password Status. Error code = 0x"
			<< std::hex << takingDieci << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->> AdminPasswordStatus e rilascio
	int varAdminPasswordStat=0;
	varAdminPasswordStat = V_INT(&var_AdminPasswordStatus);

	
	//Raccolta proprietà SYSTEMFAMILY
	_variant_t var_SystemFamily;
	HRESULT takingUndici;

	takingUndici = motherboard->Get(L"SystemFamily", 0, &var_SystemFamily, NULL, NULL);

	//Controllo errori sul recupero della propietà SYSTEMFAMILY
	if (FAILED(takingUndici))
	{
		std::cout << "Could not retrive System Family. Error code = 0x"
			<< std::hex << takingUndici << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->> SystemFamily e rilascio
	std::string varSystemFam = (const char*)_bstr_t(V_BSTR(&var_SystemFamily));
	const char * varSystemFamily = varSystemFam.c_str();

	//Raccolta proprietà SYSTEMSKUNUMBER
	_variant_t var_SystemSKUNumber;
	HRESULT takingDodici;

	takingDodici = motherboard->Get(L"SystemSKUNumber", 0, &var_SystemSKUNumber, NULL, NULL);

	//Controllo errori sul recupero della propietà SYSTEMSKUNUMBER
	if (FAILED(takingDodici))
	{
		std::cout << "Could not retrive System SKU Number. Error code = 0x"
			<< std::hex << takingDodici << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->> SystemSKUNumber e rilascio
	std::string varSystemSKUNumb = (const char*)_bstr_t(V_BSTR(&var_SystemSKUNumber));
	const char * varSystemSKUNumber = varSystemSKUNumb.c_str();

	// Raccolta propietà TotalPhysicalMemory
	_variant_t varTotalPhysicalMemoryMb;
	taking = motherboard->Get(L"TotalPhysicalMemory", 0, &varTotalPhysicalMemoryMb, NULL, NULL);

	//Controllo errori sul recupero della propietà TotalPhysicalMemory
	if (FAILED(taking))
	{
		std::cout << "Could retrive TotalPhysicalMemory. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>TotalPhysicalMemory e rilascio
	int varTotalPhysicalMemorypp = 0;
	varTotalPhysicalMemorypp = V_INT(&varTotalPhysicalMemoryMb);
	char var_TotalPhysicalMemory[256];
	sprintf(var_TotalPhysicalMemory, "%d", varTotalPhysicalMemorypp);
	VariantClear(&varTotalPhysicalMemoryMb);

	// Cleanup
	// ========

	service.Release();
	locator.Release();
	enumerator.Release();
/*--------------------------------------------------------------------------------------------------------------*/
	// Trova il riferimento alla classe com.quinta.Sistema
	jclass cls = env->FindClass("com/quinta/Sistema");
/*--------------------------------------------------------------------------------------------------------------*/

	//Conversione variabili
	jstring manufact;
	manufact=env->NewStringUTF(var_Manufacture);

	// Trova l'IDmetodo del metodo "setMbManufacturer", che prende String come argomento e ritorna void
	jmethodID changeManufacturer = env->GetMethodID(cls, "setMbManufacturer", "(Ljava/lang/String;)V");
	if (NULL == changeManufacturer) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setMbManufacturer"
	env->CallVoidMethod(thisObj, changeManufacturer, manufact);

	//Conversione variabili
	jstring modello;
	modello = env->NewStringUTF(varModel);

	// Trova l'IDmetodo del metodo "setMbModel", che prende String come argomento e ritorna void
	jmethodID changeModel = env->GetMethodID(cls, "setMbModel", "(Ljava/lang/String;)V");
	if (NULL == changeModel) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setMbModel"
	env->CallVoidMethod(thisObj, changeModel, modello);

	//Conversione variabili
	jstring name;
	name = env->NewStringUTF(varName);

	// Trova l'IDmetodo del metodo "setMbName", che prende String come argomento e ritorna void
	jmethodID changeName = env->GetMethodID(cls, "setMbName", "(Ljava/lang/String;)V");
	if (NULL == changeName) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setMbModel"
	env->CallVoidMethod(thisObj, changeName, name);

	// Conversione variabili
	jstring Description;
	Description = env->NewStringUTF(varDescription);

	// Trova l'IDmetodo del metodo "setMbDescription", che prende String come argomento e ritorna void
	jmethodID changeDescription = env->GetMethodID(cls, "setMbDescription", "(Ljava/lang/String;)V");
	if (NULL == changeDescription) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setMbDescription"
	env->CallVoidMethod(thisObj, changeDescription, Description);

	// Conversione variabili
	jstring DNSHostName;
	DNSHostName = env->NewStringUTF(varDNSHostName);

	// Trova l'IDmetodo del metodo "setMbDNSHostName", che prende String come argomento e ritorna void
	jmethodID changeDNSHostName = env->GetMethodID(cls, "setMbDNSHostName", "(Ljava/lang/String;)V");
	if (NULL == changeDNSHostName) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setMbDNSHostName"
	env->CallVoidMethod(thisObj, changeDNSHostName, DNSHostName);
	
	// Conversione variabili
	jstring Domain;
	Domain = env->NewStringUTF(varDomain);

	// Trova l'IDmetodo del metodo "setMbDomain", che prende String come argomento e ritorna void
	jmethodID changeDomain = env->GetMethodID(cls, "setMbDomain", "(Ljava/lang/String;)V");
	if (NULL == changeDomain) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setMbDomain"
	env->CallVoidMethod(thisObj, changeDomain, Domain);

	// Conversione variabili
	jstring Status;
	Status = env->NewStringUTF(varStatus);

	// Trova l'IDmetodo del metodo "setMbStatus", che prende String come argomento e ritorna void
	jmethodID changeStatus = env->GetMethodID(cls, "setMbStatus", "(Ljava/lang/String;)V");
	if (NULL == changeStatus) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setMbStatus"
	env->CallVoidMethod(thisObj, changeStatus, Status);

	// Conversione variabili
	jstring SystemType;
	SystemType = env->NewStringUTF(varSystemType);

	// Trova l'IDmetodo del metodo "setMbSystemType", che prende String come argomento e ritorna void
	jmethodID changeSystemType = env->GetMethodID(cls, "setMbSystemType", "(Ljava/lang/String;)V");
	if (NULL == changeSystemType) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setMbSystemType"
	env->CallVoidMethod(thisObj, changeSystemType, SystemType);
	
	// Conversione variabili
	jstring UserName;
	UserName = env->NewStringUTF(varUserName);

	// Trova l'IDmetodo del metodo "setMbUserName", che prende String come argomento e ritorna void
	jmethodID changeUserName = env->GetMethodID(cls, "setMbUserName", "(Ljava/lang/String;)V");
	if (NULL == changeUserName) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setMbUserName"
	env->CallVoidMethod(thisObj, changeUserName, UserName);
	
	// Conversione variabili
	jint AdminPasswordStatus;
	AdminPasswordStatus = varAdminPasswordStat;

	// Trova l'IDmetodo del metodo "setMbAdminPasswordStatus", che prende String come argomento e ritorna void
	jmethodID changeAdminPasswordStatus = env->GetMethodID(cls, "setMbAdminPasswordStatus", "(I)V");
	if (NULL == changeAdminPasswordStatus) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setMbAdminPasswordStatus"
	env->CallVoidMethod(thisObj, changeAdminPasswordStatus, AdminPasswordStatus);

	// Conversione variabili
	jstring SystemFamily;
	SystemFamily = env->NewStringUTF(varSystemFamily);

	// Trova l'IDmetodo del metodo "setMbSystemFamily", che prende String come argomento e ritorna void
	jmethodID changeSystemFamily = env->GetMethodID(cls, "setMbSystemFamily", "(Ljava/lang/String;)V");
	if (NULL == changeSystemFamily) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setMbSystemFamily"
	env->CallVoidMethod(thisObj, changeSystemFamily, SystemFamily);

	// Conversione variabili
	jstring SystemSKUNumber;
	SystemSKUNumber = env->NewStringUTF(varSystemSKUNumber);

	// Trova l'IDmetodo del metodo "setMbSystemSKUNumber", che prende String come argomento e ritorna void
	jmethodID changeSystemSKUNumber = env->GetMethodID(cls, "setMbSystemSKUNumber", "(Ljava/lang/String;)V");
	if (NULL == changeSystemSKUNumber) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setMbSystemSKUNumber"
	env->CallVoidMethod(thisObj, changeSystemSKUNumber, SystemSKUNumber);

	// Conversione variabili
	jstring TotalPhysicalMemory;
	TotalPhysicalMemory = env->NewStringUTF(var_TotalPhysicalMemory);

	// Trova l'IDmetodo del metodo "setMbTotalPhysicalMemory", che prende String come argomento e ritorna void
	jmethodID changeTotalPhysicalMemory = env->GetMethodID(cls, "setMbTotalPhysicalMemory", "(Ljava/lang/String;)V");
	if (NULL == changeTotalPhysicalMemory) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setMbTotalPhysicalMemory"
	env->CallVoidMethod(thisObj, changeTotalPhysicalMemory, TotalPhysicalMemory);
	
	/*--------------------------------------------------------------------------------------------------------------*/

	//Creazione puntatore ai servizi WMI
	CComPtr< IWbemLocator > loc;
	puntatore = CoCreateInstance(CLSID_WbemAdministrativeLocator, NULL, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID *)&loc);

	//Controllo errori sulla creazione del puntatore ai servizi WMI
	if (FAILED(puntatore))
	{
		std::cout << "Failed to create pointer to WMI services. Err code = 0x"
			<< std::hex << puntatore << std::endl;
		CoUninitialize();
		return;     // Program has failed.
	}

	//Connessione alla LOCAL MACHINE
	CComPtr< IWbemServices > serv;
	servizio = loc->ConnectServer(L"root\\cimv2", NULL, NULL, NULL, WBEM_FLAG_CONNECT_USE_MAX_WAIT, NULL, NULL, &serv);

	//Controllo errori sulla connessione alla LOCAL MACHINE
	if (FAILED(servizio))
	{
		std::cout << "Could not connect. Error code = 0x"
			<< std::hex << servizio << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}


	//QUERY AT CIM_Card PROVIDER
	CComPtr< IEnumWbemClassObject > enume;
	query = serv->ExecQuery(L"WQL", L"SELECT * FROM CIM_Card", WBEM_FLAG_FORWARD_ONLY, NULL, &enume);

	//Controllo errori sulla query
	if (FAILED(query))
	{
		std::cout << "Query as failed. Error code = 0x"
			<< std::hex << query << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//Lettura della query
	ULONG returnedVl;
	CComPtr< IWbemClassObject > mobo;
	reading = enume->Next(WBEM_INFINITE, 1L, &mobo, &returnedVl);

	//Controllo sulla creazione della struttura ospitante dei dati raccolti tramite la query
	if (FAILED(reading))
	{
		std::cout << "Could not read query. Error code = 0x"
			<< std::hex << reading << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//Raccolta propietà SerialNumber
	_variant_t varSerialNumber;
	taking = mobo->Get(L"SerialNumber", 0, &varSerialNumber, NULL, NULL);

	//Controllo errori sul recupero della propietà RequirementsDescription
	if (FAILED(taking))
	{
		std::cout << "Could retrive SerialNumber. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->> SerialNumber e rilascio
	std::string varSerialNo = (const char*)_bstr_t(V_BSTR(&varSerialNumber));
	const char * var_SerialNumber = varSerialNo.c_str();
	VariantClear(&varSerialNumber);

	//Cleanup
	enume.Release();

	/*--------------------------------------------------------------------------------------------------------------*/
	
	// Conversione variabili
	jstring SerialNumber;
	SerialNumber = env->NewStringUTF(var_SerialNumber);

	// Trova l'IDmetodo del metodo "setBbSerialNumber", che prende String come argomento e ritorna void
	jmethodID changeSerialNumber = env->GetMethodID(cls, "setBbSerialNumber", "(Ljava/lang/String;)V");
	if (NULL == changeSerialNumber) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setBbSerialNumber"
	env->CallVoidMethod(thisObj, changeSerialNumber, SerialNumber);

	/*--------------------------------------------------------------------------------------------------------------*/

	//QUERY AT Win32_ComputerSystem PROVIDER
	CComPtr< IEnumWbemClassObject > enu;
	query = serv->ExecQuery(L"WQL", L"SELECT * FROM Win32_OperatingSystem", WBEM_FLAG_FORWARD_ONLY, NULL, &enu);

	//Controllo errori sulla query
	if (FAILED(query))
	{
		std::cout << "Query as failed. Error code = 0x"
			<< std::hex << query << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//Lettura della query
	ULONG returnedV;
	CComPtr< IWbemClassObject > mob;
	reading = enu->Next(WBEM_INFINITE, 1L, &mob, &returnedV);

	//Controllo sulla creazione della struttura ospitante dei dati raccolti tramite la query
	if (FAILED(reading))
	{
		std::cout << "Could not read query. Error code = 0x"
			<< std::hex << reading << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}
	
	//Raccolta propietà BootDevice
	_variant_t varBootDevice;
	taking = mob->Get(L"BootDevice", 0, &varBootDevice, NULL, NULL);

	//Controllo errori sul recupero della propietà BootDevice
	if (FAILED(taking))
	{
		std::cout << "Could retrive BootDevice. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->> BootDevice e rilascio
	std::string varBootDev = (const char*)_bstr_t(V_BSTR(&varBootDevice));
	const char * var_BootDevice = varBootDev.c_str();
	VariantClear(&varBootDevice);

	//Raccolta propietà BuildNumber
	_variant_t varBuildNumber;
	taking = mob->Get(L"BuildNumber", 0, &varBuildNumber, NULL, NULL);

	//Controllo errori sul recupero della propietà BuildNumber
	if (FAILED(taking))
	{
		std::cout << "Could retrive BuildNumber. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->> BuildNumber e rilascio
	std::string varBuildNo = (const char*)_bstr_t(V_BSTR(&varBuildNumber));
	const char * var_BuildNumber = varBuildNo.c_str();
	VariantClear(&varBuildNumber);

	//Raccolta propietà BuildType
	_variant_t varBuildType;
	taking = mob->Get(L"BuildType", 0, &varBuildType, NULL, NULL);

	//Controllo errori sul recupero della propietà BuildType
	if (FAILED(taking))
	{
		std::cout << "Could retrive BuildType. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->> BuildType e rilascio
	std::string varBuildTy = (const char*)_bstr_t(V_BSTR(&varBuildType));
	const char * var_BuildType = varBuildTy.c_str();
	VariantClear(&varBuildType);

	//Raccolta propietà CodeSet
	_variant_t varCodeSet;
	taking = mob->Get(L"CodeSet", 0, &varCodeSet, NULL, NULL);

	//Controllo errori sul recupero della propietà CodeSet
	if (FAILED(taking))
	{
		std::cout << "Could retrive CodeSet. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->> CodeSet e rilascio
	std::string varCodeS = (const char*)_bstr_t(V_BSTR(&varCodeSet));
	const char * var_CodeSet = varCodeS.c_str();
	VariantClear(&varCodeSet);

	//Raccolta propietà CountryCode
	_variant_t varCountryCode;
	taking = mob->Get(L"CountryCode", 0, &varCountryCode, NULL, NULL);

	//Controllo errori sul recupero della propietà CountryCode
	if (FAILED(taking))
	{
		std::cout << "Could retrive CountryCode. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->> CountryCode e rilascio
	std::string varCountryC = (const char*)_bstr_t(V_BSTR(&varCountryCode));
	const char * var_CountryCode = varCountryC.c_str();
	VariantClear(&varCountryCode);

	//Raccolta propietà SystemDirectory
	_variant_t varSystemDirectory;
	taking = mob->Get(L"SystemDirectory", 0, &varSystemDirectory, NULL, NULL);

	//Controllo errori sul recupero della propietà SystemDirectory
	if (FAILED(taking))
	{
		std::cout << "Could retrive SystemDirectory. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->> SystemDirectory e rilascio
	std::string varSystemDirector = (const char*)_bstr_t(V_BSTR(&varSystemDirectory));
	const char * var_SystemDirectory = varSystemDirector.c_str();
	VariantClear(&varSystemDirectory);

	//Raccolta propietà SystemDevice
	_variant_t varSystemDevice;
	taking = mob->Get(L"SystemDevice", 0, &varSystemDevice, NULL, NULL);

	//Controllo errori sul recupero della propietà SystemDevice
	if (FAILED(taking))
	{
		std::cout << "Could retrive SystemDevice. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->> SystemDevice e rilascio
	std::string varSystemDevic = (const char*)_bstr_t(V_BSTR(&varSystemDevice));
	const char * var_SystemDevice = varSystemDevic.c_str();
	VariantClear(&varSystemDevice);

	//Raccolta propietà SystemDrive
	_variant_t varSystemDrive;
	taking = mob->Get(L"SystemDrive", 0, &varSystemDrive, NULL, NULL);

	//Controllo errori sul recupero della propietà SystemDrive
	if (FAILED(taking))
	{
		std::cout << "Could retrive SystemDrive. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->> SystemDrive e rilascio
	std::string varSystemDriv = (const char*)_bstr_t(V_BSTR(&varSystemDrive));
	const char * var_SystemDrive = varSystemDriv.c_str();
	VariantClear(&varSystemDrive);

	//Raccolta propietà WindowsDirectory
	_variant_t varWindowsDirectory;
	taking = mob->Get(L"WindowsDirectory", 0, &varWindowsDirectory, NULL, NULL);

	//Controllo errori sul recupero della propietà WindowsDirectory
	if (FAILED(taking))
	{
		std::cout << "Could retrive WindowsDirectory. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->> WindowsDirectory e rilascio
	std::string varWindowsDirecto = (const char*)_bstr_t(V_BSTR(&varWindowsDirectory));
	const char * var_WindowsDirectory = varWindowsDirecto.c_str();
	VariantClear(&varWindowsDirectory);

	//Cleanup
	enu.Release();

	/*--------------------------------------------------------------------------------------------------------------*/
	
	// Conversione variabili
	jstring BootDevice;
	BootDevice = env->NewStringUTF(var_BootDevice);

	// Trova l'IDmetodo del metodo "setOsBootDevice", che prende String come argomento e ritorna void
	jmethodID changeBootDevice = env->GetMethodID(cls, "setOsBootDevice", "(Ljava/lang/String;)V");
	if (NULL == changeBootDevice) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setOsBootDevice"
	env->CallVoidMethod(thisObj, changeBootDevice, BootDevice);

	// Conversione variabili
	jstring BuildNumber;
	BuildNumber = env->NewStringUTF(var_BuildNumber);

	// Trova l'IDmetodo del metodo "setOsBuildNumber", che prende String come argomento e ritorna void
	jmethodID changeBuildNumber = env->GetMethodID(cls, "setOsBuildNumber", "(Ljava/lang/String;)V");
	if (NULL == changeBuildNumber) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setOsBuildNumber"
	env->CallVoidMethod(thisObj, changeBuildNumber, BuildNumber);

	// Conversione variabili
	jstring BuildType;
	BuildType = env->NewStringUTF(var_BuildType);

	// Trova l'IDmetodo del metodo "setOsBuildType", che prende String come argomento e ritorna void
	jmethodID changeBuildType = env->GetMethodID(cls, "setOsBuildType", "(Ljava/lang/String;)V");
	if (NULL == changeBuildType) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setOsBuildType"
	env->CallVoidMethod(thisObj, changeBuildType, BuildType);

	// Conversione variabili
	jstring CodeSet;
	CodeSet = env->NewStringUTF(var_CodeSet);

	// Trova l'IDmetodo del metodo "setOsCodeSet", che prende String come argomento e ritorna void
	jmethodID changeCodeSet = env->GetMethodID(cls, "setOsCodeSet", "(Ljava/lang/String;)V");
	if (NULL == changeCodeSet) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setOsCodeSet"
	env->CallVoidMethod(thisObj, changeCodeSet, CodeSet);

	// Conversione variabili
	jstring CountryCode;
	CountryCode = env->NewStringUTF(var_CountryCode);

	// Trova l'IDmetodo del metodo "setOsCountryCode", che prende String come argomento e ritorna void
	jmethodID changeCountryCode = env->GetMethodID(cls, "setOsCountryCode", "(Ljava/lang/String;)V");
	if (NULL == changeCountryCode) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setOsCountryCode"
	env->CallVoidMethod(thisObj, changeCountryCode, CountryCode);

	// Conversione variabili
	jstring SystemDirectory;
	SystemDirectory = env->NewStringUTF(var_SystemDirectory);

	// Trova l'IDmetodo del metodo "setOsSystemDirectory", che prende String come argomento e ritorna void
	jmethodID changeSystemDirectory = env->GetMethodID(cls, "setOsSystemDirectory", "(Ljava/lang/String;)V");
	if (NULL == changeSystemDirectory) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setOsSystemDirectory"
	env->CallVoidMethod(thisObj, changeSystemDirectory, SystemDirectory);

	// Conversione variabili
	jstring SystemDevice;
	SystemDevice = env->NewStringUTF(var_SystemDevice);

	// Trova l'IDmetodo del metodo "setOsSystemDevice", che prende String come argomento e ritorna void
	jmethodID changeSystemDevice = env->GetMethodID(cls, "setOsSystemDevice", "(Ljava/lang/String;)V");
	if (NULL == changeSystemDevice) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setOsSystemDevice"
	env->CallVoidMethod(thisObj, changeSystemDevice, SystemDevice);
	
	// Conversione variabili
	jstring SystemDrive;
	SystemDrive = env->NewStringUTF(var_SystemDrive);

	// Trova l'IDmetodo del metodo "setOsSystemDrive", che prende String come argomento e ritorna void
	jmethodID changeSystemDrive = env->GetMethodID(cls, "setOsSystemDrive", "(Ljava/lang/String;)V");
	if (NULL == changeSystemDrive) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setOsSystemDrive"
	env->CallVoidMethod(thisObj, changeSystemDrive, SystemDrive);

	// Conversione variabili
	jstring WindowsDirectory;
	WindowsDirectory = env->NewStringUTF(var_WindowsDirectory);

	// Trova l'IDmetodo del metodo "setOsWindowsDirectory", che prende String come argomento e ritorna void
	jmethodID changeWindowsDirectory = env->GetMethodID(cls, "setOsWindowsDirectory", "(Ljava/lang/String;)V");
	if (NULL == changeWindowsDirectory) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setOsWindowsDirectory"
	env->CallVoidMethod(thisObj, changeWindowsDirectory, WindowsDirectory);

	/*--------------------------------------------------------------------------------------------------------------*/
	
	//QUERY AT Win32_BIOS PROVIDER
	CComPtr< IEnumWbemClassObject > en;
	query = serv->ExecQuery(L"WQL", L"SELECT * FROM Win32_BIOS", WBEM_FLAG_FORWARD_ONLY, NULL, &en);

	//Controllo errori sulla query
	if (FAILED(query))
	{
		std::cout << "Query as failed. Error code = 0x"
			<< std::hex << query << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//Lettura della query
	ULONG returned;
	CComPtr< IWbemClassObject > mo;
	reading = en->Next(WBEM_INFINITE, 1L, &mo, &returned);

	//Controllo sulla creazione della struttura ospitante dei dati raccolti tramite la query
	if (FAILED(reading))
	{
		std::cout << "Could not read query. Error code = 0x"
			<< std::hex << reading << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//Raccolta propietà SerialNumber
	_variant_t varSerialNumberBios;
	taking = mo->Get(L"SerialNumber", 0, &varSerialNumberBios, NULL, NULL);

	//Controllo errori sul recupero della propietà SerialNumber
	if (FAILED(taking))
	{
		std::cout << "Could retrive SerialNumber. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>SerialNumber e rilascio
	std::string varSerialNumberO = (const char*)_bstr_t(V_BSTR(&varSerialNumberBios));
	const char * var_SerialNumberBios = varSerialNumberO.c_str();
	VariantClear(&varSerialNumberBios);

	//Raccolta propietà SMBIOSBIOSVersion
	_variant_t varSMBIOSBIOSVersionBios;
	taking = mo->Get(L"SMBIOSBIOSVersion", 0, &varSMBIOSBIOSVersionBios, NULL, NULL);

	//Controllo errori sul recupero della propietà SMBIOSBIOSVersion
	if (FAILED(taking))
	{
		std::cout << "Could retrive SMBIOSBIOSVersion. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>SMBIOSBIOSVersion e rilascio
	std::string varSMBIOSBIOSVersionO = (const char*)_bstr_t(V_BSTR(&varSMBIOSBIOSVersionBios));
	const char * var_SMBIOSBIOSVersionBios = varSMBIOSBIOSVersionO.c_str();
	VariantClear(&varSMBIOSBIOSVersionBios);

	//Raccolta propietà SoftwareElementID
	_variant_t varSoftwareElementIDBios;
	taking = mo->Get(L"SoftwareElementID", 0, &varSoftwareElementIDBios, NULL, NULL);

	//Controllo errori sul recupero della propietà SoftwareElementID
	if (FAILED(taking))
	{
		std::cout << "Could retrive SoftwareElementID. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>SoftwareElementID e rilascio
	std::string varSoftwareElementIDO = (const char*)_bstr_t(V_BSTR(&varSoftwareElementIDBios));
	const char * var_SoftwareElementIDBios = varSoftwareElementIDO.c_str();
	VariantClear(&varSoftwareElementIDBios);

	//Raccolta propietà Status
	_variant_t varStatusBios;
	taking = mo->Get(L"Status", 0, &varStatusBios, NULL, NULL);

	//Controllo errori sul recupero della propietà Status
	if (FAILED(taking))
	{
		std::cout << "Could retrive Status. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>Status e rilascio
	std::string varStatusO = (const char*)_bstr_t(V_BSTR(&varStatusBios));
	const char * var_StatusBios = varStatusO.c_str();
	VariantClear(&varStatusBios);

	//Cleanup
	serv.Release();
	en.Release();
	
	/*--------------------------------------------------------------------------------------------------------------*/
	
	// Conversione variabili
	jstring SerialNumberBios;
	SerialNumberBios = env->NewStringUTF(var_SerialNumberBios);

	// Trova l'IDmetodo del metodo "setBsSerialNumber", che prende String come argomento e ritorna void
	jmethodID changeSerialNumberBios = env->GetMethodID(cls, "setBsSerialNumber", "(Ljava/lang/String;)V");
	if (NULL == changeSerialNumberBios) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setBsSerialNumber"
	env->CallVoidMethod(thisObj, changeSerialNumberBios, SerialNumberBios);

	// Conversione variabili
	jstring SMBIOSBIOSVersionBios;
	SMBIOSBIOSVersionBios = env->NewStringUTF(var_SMBIOSBIOSVersionBios);

	// Trova l'IDmetodo del metodo "setBsSMBIOSBIOSVersion", che prende String come argomento e ritorna void
	jmethodID changeSMBIOSBIOSVersionBios = env->GetMethodID(cls, "setBsSMBIOSBIOSVersion", "(Ljava/lang/String;)V");
	if (NULL == changeSMBIOSBIOSVersionBios) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setBsSMBIOSBIOSVersion"
	env->CallVoidMethod(thisObj, changeSMBIOSBIOSVersionBios, SMBIOSBIOSVersionBios);

	// Conversione variabili
	jstring SoftwareElementIDBios;
	SoftwareElementIDBios = env->NewStringUTF(var_SoftwareElementIDBios);

	// Trova l'IDmetodo del metodo "setBsSoftwareElementID", che prende String come argomento e ritorna void
	jmethodID changeSoftwareElementIDBios = env->GetMethodID(cls, "setBsSoftwareElementID", "(Ljava/lang/String;)V");
	if (NULL == changeSoftwareElementIDBios) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setBsSoftwareElementID"
	env->CallVoidMethod(thisObj, changeSoftwareElementIDBios, SoftwareElementIDBios);

	// Conversione variabili
	jstring StatusBios;
	StatusBios = env->NewStringUTF(var_StatusBios);

	// Trova l'IDmetodo del metodo "setBsStatus", che prende String come argomento e ritorna void
	jmethodID changeStatusBios = env->GetMethodID(cls, "setBsStatus", "(Ljava/lang/String;)V");
	if (NULL == changeStatusBios) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setBsStatus"
	env->CallVoidMethod(thisObj, changeStatusBios, StatusBios);

	/*--------------------------------------------------------------------------------------------------------------*/

	//Connessione alla LOCAL MACHINE
	CComPtr< IWbemServices > ser;
	servizio = loc->ConnectServer(L"root\\StandardCimv2", NULL, NULL, NULL, WBEM_FLAG_CONNECT_USE_MAX_WAIT, NULL, NULL, &ser);

	//Controllo errori sulla connessione alla LOCAL MACHINE
	if (FAILED(servizio))
	{
		std::cout << "Could not connect. Error code = 0x"
			<< std::hex << servizio << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//QUERY AT Win32_NetworkAdapter PROVIDER
	CComPtr< IEnumWbemClassObject > e;
	query = ser->ExecQuery(L"WQL", L"SELECT * FROM MSFT_NetAdapter", WBEM_FLAG_FORWARD_ONLY, NULL, &e);

	//Controllo errori sulla query
	if (FAILED(query))
	{
		std::cout << "Query as failed. Error code = 0x"
			<< std::hex << query << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//Lettura della query
	ULONG returne;
	CComPtr< IWbemClassObject > m;
	reading = e->Next(WBEM_INFINITE, 1L, &m, &returne);

	//Controllo sulla creazione della struttura ospitante dei dati raccolti tramite la query
	if (FAILED(reading))
	{
		std::cout << "Could not read query. Error code = 0x"
			<< std::hex << reading << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}
	
	
	//Raccolta propietà Name
	_variant_t varNameNa;
	taking = m->Get(L"Name", 0, &varNameNa, NULL, NULL);

	//Controllo errori sul recupero della propietà Name
	if (FAILED(taking))
	{
		std::cout << "Could retrive Name. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>Name e rilascio
	std::string varNameO = (const char*)_bstr_t(V_BSTR(&varNameNa));
	const char * var_N = varNameO.c_str();
	VariantClear(&varNameNa);
	
	//Raccolta propietà DeviceID
	_variant_t varDeviceIDNa;
	taking = m->Get(L"DeviceID", 0, &varDeviceIDNa, NULL, NULL);

	//Controllo errori sul recupero della propietà DeviceID
	if (FAILED(taking))
	{
		std::cout << "Could retrive DeviceID. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>DeviceID e rilascio
	std::string varDeviceIDO = (const char*)_bstr_t(V_BSTR(&varDeviceIDNa));
	const char * var_DeviceID = varDeviceIDO.c_str();
	VariantClear(&varDeviceIDNa);
	
	//Raccolta propietà PNPDeviceID
	_variant_t varPNPDeviceIDNa;
	taking = m->Get(L"PNPDeviceID", 0, &varPNPDeviceIDNa, NULL, NULL);

	//Controllo errori sul recupero della propietà PNPDeviceID
	if (FAILED(taking))
	{
		std::cout << "Could retrive PNPDeviceID. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>PNPDeviceID e rilascio
	std::string varPNPDeviceIDO = (const char*)_bstr_t(V_BSTR(&varPNPDeviceIDNa));
	const char * var_PNPDeviceID = varPNPDeviceIDO.c_str();
	VariantClear(&varPNPDeviceIDNa);
	
	// Raccolta propietà StatusInfo
	_variant_t varStatusInfoNa;
	taking = m->Get(L"StatusInfo", 0, &varStatusInfoNa, NULL, NULL);

	//Controllo errori sul recupero della propietà StatusInfo
	if (FAILED(taking))
	{
		std::cout << "Could retrive StatusInfo. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>StatusInfo e rilascio
	int varStatusInfoop = 0;
	varStatusInfoop = V_INT(&varStatusInfoNa);
	char var_StatusInfoo[256];
	sprintf(var_StatusInfoo, "%d", varStatusInfoop);
	VariantClear(&varStatusInfoNa);

	// Raccolta propietà Speed
	_variant_t varSpeedNa;
	taking = m->Get(L"Speed", 0, &varSpeedNa, NULL, NULL);

	//Controllo errori sul recupero della propietà Speed
	if (FAILED(taking))
	{
		std::cout << "Could retrive Speed. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>Speed e rilascio
	int varSpeedp = 0;
	varSpeedp = V_INT(&varSpeedNa);
	char var_Speed[256];
	sprintf(var_Speed, "%d", varSpeedp);
	VariantClear(&varSpeedNa);

	// Raccolta propietà PortType
	_variant_t varPortTypeNa;
	taking = m->Get(L"PortType", 0, &varPortTypeNa, NULL, NULL);

	//Controllo errori sul recupero della propietà PortType
	if (FAILED(taking))
	{
		std::cout << "Could retrive PortType. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>PortType e rilascio
	int varPortTypep = 0;
	varPortTypep = V_INT(&varPortTypeNa);
	char var_PortType[256];
	sprintf(var_PortType, "%d", varPortTypep);
	VariantClear(&varPortTypeNa);

	//Raccolta propietà PermanentAddress
	_variant_t varPermanentAddressNa;
	taking = m->Get(L"PermanentAddress", 0, &varPermanentAddressNa, NULL, NULL);

	//Controllo errori sul recupero della propietà PermanentAddress
	if (FAILED(taking))
	{
		std::cout << "Could retrive PermanentAddress. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>OtherPortType e rilascio
	std::string varPermanentAddressO = (const char*)_bstr_t(V_BSTR(&varPermanentAddressNa));
	const char * var_PermanentAddress = varPermanentAddressO.c_str();
	VariantClear(&varPermanentAddressNa);

	//Raccolta propietà InterfaceDescription
	_variant_t varInterfaceDescriptionNa;
	taking = m->Get(L"InterfaceDescription", 0, &varInterfaceDescriptionNa, NULL, NULL);

	//Controllo errori sul recupero della propietà InterfaceDescription
	if (FAILED(taking))
	{
		std::cout << "Could retrive InterfaceDescription. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>InterfaceDescription e rilascio
	std::string varInterfaceDescriptionO = (const char*)_bstr_t(V_BSTR(&varInterfaceDescriptionNa));
	const char * var_InterfaceDescription = varInterfaceDescriptionO.c_str();
	VariantClear(&varInterfaceDescriptionNa);

	//Raccolta propietà InterfaceName
	_variant_t varInterfaceNameNa;
	taking = m->Get(L"InterfaceName", 0, &varInterfaceNameNa, NULL, NULL);

	//Controllo errori sul recupero della propietà InterfaceName
	if (FAILED(taking))
	{
		std::cout << "Could retrive InterfaceName. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>InterfaceName e rilascio
	std::string varInterfaceNameO = (const char*)_bstr_t(V_BSTR(&varInterfaceNameNa));
	const char * var_InterfaceName = varInterfaceNameO.c_str();
	VariantClear(&varInterfaceNameNa);

	// Raccolta propietà InterfaceIndex
	_variant_t varInterfaceIndexNa;
	taking = m->Get(L"InterfaceIndex", 0, &varInterfaceIndexNa, NULL, NULL);

	//Controllo errori sul recupero della propietà InterfaceIndex
	if (FAILED(taking))
	{
		std::cout << "Could retrive InterfaceIndex. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>InterfaceIndex e rilascio
	int varInterfaceIndexp = 0;
	varInterfaceIndexp = V_INT(&varInterfaceIndexNa);
	char var_InterfaceIndex[256];
	sprintf(var_InterfaceIndex, "%d", varInterfaceIndexp);
	VariantClear(&varInterfaceIndexNa);

	// Raccolta propietà DeviceName
	_variant_t varDeviceNameNa;
	taking = m->Get(L"DeviceName", 0, &varDeviceNameNa, NULL, NULL);

	//Controllo errori sul recupero della propietà DeviceName
	if (FAILED(taking))
	{
		std::cout << "Could retrive DeviceName. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>DeviceName e rilascio
	std::string varDeviceNameO = (const char*)_bstr_t(V_BSTR(&varDeviceNameNa));
	const char * var_DeviceName = varDeviceNameO.c_str();
	VariantClear(&varDeviceNameNa);

	// Raccolta propietà VlanID
	_variant_t varVlanIDNa;
	taking = m->Get(L"VlanID", 0, &varVlanIDNa, NULL, NULL);

	//Controllo errori sul recupero della propietà VlanID
	if (FAILED(taking))
	{
		std::cout << "Could retrive VlanID. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>VlanID e rilascio
	int varVlanIDp = 0;
	varVlanIDp = V_INT(&varVlanIDNa);
	char var_VlanID[256];
	sprintf(var_VlanID, "%d", varVlanIDp);
	VariantClear(&varVlanIDNa);

	// Raccolta propietà DriverDate
	_variant_t varDriverDateNa;
	taking = m->Get(L"DriverDate", 0, &varDriverDateNa, NULL, NULL);

	//Controllo errori sul recupero della propietà DriverDate
	if (FAILED(taking))
	{
		std::cout << "Could retrive DriverDate. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>DriverDate e rilascio
	std::string varDriverDateO = (const char*)_bstr_t(V_BSTR(&varDriverDateNa));
	const char * var_DriverDate = varDriverDateO.c_str();
	VariantClear(&varDriverDateNa);

	// Raccolta propietà DriverVersionString
	_variant_t varDriverVersionStringNa;
	taking = m->Get(L"DriverVersionString", 0, &varDriverVersionStringNa, NULL, NULL);

	//Controllo errori sul recupero della propietà DriverVersionString
	if (FAILED(taking))
	{
		std::cout << "Could retrive DriverVersionString. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>DriverVersionString e rilascio
	std::string varDriverVersionStringO = (const char*)_bstr_t(V_BSTR(&varDriverVersionStringNa));
	const char * var_DriverVersionString = varDriverVersionStringO.c_str();
	VariantClear(&varDriverVersionStringNa);

	// Raccolta propietà DriverName
	_variant_t varDriverNameNa;
	taking = m->Get(L"DriverName", 0, &varDriverNameNa, NULL, NULL);

	//Controllo errori sul recupero della propietà DriverName
	if (FAILED(taking))
	{
		std::cout << "Could retrive DriverName. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>DriverName e rilascio
	std::string varDriverNameO = (const char*)_bstr_t(V_BSTR(&varDriverNameNa));
	const char * var_DriverName = varDriverNameO.c_str();
	VariantClear(&varDriverNameNa);

	// Raccolta propietà DriverDescription
	_variant_t varDriverDescriptionNa;
	taking = m->Get(L"DriverDescription", 0, &varDriverDescriptionNa, NULL, NULL);

	//Controllo errori sul recupero della propietà DriverDescription
	if (FAILED(taking))
	{
		std::cout << "Could retrive DriverDescription. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>DriverDescription e rilascio
	std::string varDriverDescriptionO = (const char*)_bstr_t(V_BSTR(&varDriverDescriptionNa));
	const char * var_DriverDescription = varDriverDescriptionO.c_str();
	VariantClear(&varDriverDescriptionNa);

	// Raccolta propietà DriverProvider
	_variant_t varDriverProviderNa;
	taking = m->Get(L"DriverProvider", 0, &varDriverProviderNa, NULL, NULL);

	//Controllo errori sul recupero della propietà DriverProvider
	if (FAILED(taking))
	{
		std::cout << "Could retrive DriverProvider. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>DriverProvider e rilascio
	std::string varDriverProviderO = (const char*)_bstr_t(V_BSTR(&varDriverProviderNa));
	const char * var_DriverProvider = varDriverProviderO.c_str();
	VariantClear(&varDriverProviderNa);

	// Raccolta propietà ComponentID
	_variant_t varComponentIDNa;
	taking = m->Get(L"ComponentID", 0, &varComponentIDNa, NULL, NULL);

	//Controllo errori sul recupero della propietà ComponentID
	if (FAILED(taking))
	{
		std::cout << "Could retrive ComponentID. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>ComponentID e rilascio
	std::string varComponentIDO = (const char*)_bstr_t(V_BSTR(&varComponentIDNa));
	const char * var_ComponentID = varComponentIDO.c_str();
	VariantClear(&varComponentIDNa);

	// Raccolta propietà Availability
	_variant_t varAvailabilityNa;
	taking = m->Get(L"Availability", 0, &varAvailabilityNa, NULL, NULL);

	//Controllo errori sul recupero della propietà Availability
	if (FAILED(taking))
	{
		std::cout << "Could retrive Availability. Error code = 0x"
			<< std::hex << taking << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//CONVERSIONE VARIANT --->>Availability e rilascio
	int varAvailabilityp = 0;
	varAvailabilityp = V_INT(&varAvailabilityNa);
	char var_Availability[256];
	sprintf(var_Availability, "%d", varAvailabilityp);
	VariantClear(&varAvailabilityNa);

	// Cleanup
	ser.Release();
	e.Release();

	/*--------------------------------------------------------------------------------------------------------------*/
	
	// Conversione variabili
	jstring NameNa;
	NameNa = env->NewStringUTF(var_N);

	// Trova l'IDmetodo del metodo "setNaName", che prende String come argomento e ritorna void
	jmethodID changeNameNa = env->GetMethodID(cls, "setNaName", "(Ljava/lang/String;)V");
	if (NULL == changeNameNa) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setNaName"
	env->CallVoidMethod(thisObj, changeNameNa, NameNa);
	
		// Conversione variabili
	jstring DeviceIDNa;
	DeviceIDNa = env->NewStringUTF(var_DeviceID);

	// Trova l'IDmetodo del metodo "setNaDeviceID", che prende String come argomento e ritorna void
	jmethodID changeDeviceID = env->GetMethodID(cls, "setNaDeviceID", "(Ljava/lang/String;)V");
	if (NULL == changeDeviceID) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setNaDeviceID"
	env->CallVoidMethod(thisObj, changeDeviceID, DeviceIDNa);
	
	// Conversione variabili
	jstring PNPDeviceIDNa;
	PNPDeviceIDNa = env->NewStringUTF(var_PNPDeviceID);

	// Trova l'IDmetodo del metodo "setNaPNPDeviceID", che prende String come argomento e ritorna void
	jmethodID changePNPDeviceIDNa = env->GetMethodID(cls, "setNaPNPDeviceID", "(Ljava/lang/String;)V");
	if (NULL == changePNPDeviceIDNa) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setNaPNPDeviceID"
	env->CallVoidMethod(thisObj, changePNPDeviceIDNa, PNPDeviceIDNa);

	// Conversione variabili
	jstring StatusInfoNa;
	StatusInfoNa = env->NewStringUTF(var_StatusInfoo);

	// Trova l'IDmetodo del metodo "setNaStatusInfo", che prende String come argomento e ritorna void
	jmethodID changeStatusInfoNa = env->GetMethodID(cls, "setNaStatusInfo", "(Ljava/lang/String;)V");
	if (NULL == changeStatusInfoNa) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setNaStatusInfo"
	env->CallVoidMethod(thisObj, changeStatusInfoNa, StatusInfoNa);

	// Conversione variabili
	jstring SpeedNa;
	SpeedNa = env->NewStringUTF(var_Speed);

	// Trova l'IDmetodo del metodo "setNaSpeed", che prende String come argomento e ritorna void
	jmethodID changeSpeedNa = env->GetMethodID(cls, "setNaSpeed", "(Ljava/lang/String;)V");
	if (NULL == changeSpeedNa) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setNaSpeed"
	env->CallVoidMethod(thisObj, changeSpeedNa, SpeedNa);

	// Conversione variabili
	jstring PortTypeNa;
	PortTypeNa = env->NewStringUTF(var_PortType);

	// Trova l'IDmetodo del metodo "setNaPortType", che prende String come argomento e ritorna void
	jmethodID changePortTypeNa = env->GetMethodID(cls, "setNaPortType", "(Ljava/lang/String;)V");
	if (NULL == changePortTypeNa) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setNaPortType"
	env->CallVoidMethod(thisObj, changePortTypeNa, PortTypeNa);
	
	// Conversione variabili
	jstring PermanentAddressNa;
	PermanentAddressNa = env->NewStringUTF(var_PermanentAddress);

	// Trova l'IDmetodo del metodo "setNaPermanentAddress", che prende String come argomento e ritorna void
	jmethodID changePermanentAddressNa = env->GetMethodID(cls, "setNaPermanentAddress", "(Ljava/lang/String;)V");
	if (NULL == changePermanentAddressNa) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setNaPermanentAddress"
	env->CallVoidMethod(thisObj, changePermanentAddressNa, PermanentAddressNa);

	// Conversione variabili
	jstring InterfaceDescriptionNa;
	InterfaceDescriptionNa = env->NewStringUTF(var_InterfaceDescription);

	// Trova l'IDmetodo del metodo "setNaInterfaceDescription", che prende String come argomento e ritorna void
	jmethodID changeInterfaceDescriptionNa = env->GetMethodID(cls, "setNaInterfaceDescription", "(Ljava/lang/String;)V");
	if (NULL == changeInterfaceDescriptionNa) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setNaInterfaceDescription" 
	env->CallVoidMethod(thisObj, changeInterfaceDescriptionNa, InterfaceDescriptionNa);

	// Conversione variabili
	jstring InterfaceNameNa;
	InterfaceNameNa = env->NewStringUTF(var_InterfaceName);

	// Trova l'IDmetodo del metodo "setNaInterfaceName", che prende String come argomento e ritorna void
	jmethodID changeInterfaceNameNa = env->GetMethodID(cls, "setNaInterfaceName", "(Ljava/lang/String;)V");
	if (NULL == changeInterfaceNameNa) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setNaInterfaceName" InterfaceName
	env->CallVoidMethod(thisObj, changeInterfaceNameNa, InterfaceNameNa);
	
	// Conversione variabili
	jstring InterfaceIndexNa;
	InterfaceIndexNa = env->NewStringUTF(var_InterfaceIndex);

	// Trova l'IDmetodo del metodo "setNaInterfaceIndex", che prende String come argomento e ritorna void
	jmethodID changeInterfaceIndexNa = env->GetMethodID(cls, "setNaInterfaceIndex", "(Ljava/lang/String;)V");
	if (NULL == changeInterfaceIndexNa) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setNaInterfaceIndex"
	env->CallVoidMethod(thisObj, changeInterfaceIndexNa, InterfaceIndexNa); 

	// Conversione variabili
	jstring DeviceNameNa;
	DeviceNameNa = env->NewStringUTF(var_DeviceName);

	// Trova l'IDmetodo del metodo "setNaDeviceName", che prende String come argomento e ritorna void
	jmethodID changeDeviceNameNa = env->GetMethodID(cls, "setNaDeviceName", "(Ljava/lang/String;)V");
	if (NULL == changeDeviceNameNa) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setNaDeviceName"
	env->CallVoidMethod(thisObj, changeDeviceNameNa, DeviceNameNa);
	
	// Conversione variabili
	jstring VlanIDNa;
	VlanIDNa = env->NewStringUTF(var_VlanID);

	// Trova l'IDmetodo del metodo "setNaVlanID", che prende String come argomento e ritorna void
	jmethodID changeVlanIDNa = env->GetMethodID(cls, "setNaVlanID", "(Ljava/lang/String;)V");
	if (NULL == changeVlanIDNa) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setNaVlanID"
	env->CallVoidMethod(thisObj, changeVlanIDNa, VlanIDNa);
	
	// Conversione variabili
	jstring DriverDateNa;
	DriverDateNa = env->NewStringUTF(var_DriverDate);

	// Trova l'IDmetodo del metodo "setNaDriverDate", che prende String come argomento e ritorna void
	jmethodID changeDriverDateNa = env->GetMethodID(cls, "setNaDriverDate", "(Ljava/lang/String;)V");
	if (NULL == changeDriverDateNa) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setNaDriverDate"
	env->CallVoidMethod(thisObj, changeDriverDateNa, DriverDateNa);
	
	// Conversione variabili
	jstring DriverVersionStringNa;
	DriverVersionStringNa = env->NewStringUTF(var_DriverVersionString);

	// Trova l'IDmetodo del metodo "setNaDriverVersionString", che prende String come argomento e ritorna void
	jmethodID changeDriverVersionStringNa = env->GetMethodID(cls, "setNaDriverVersionString", "(Ljava/lang/String;)V");
	if (NULL == changeDriverVersionStringNa) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setNaDriverVersionString"
	env->CallVoidMethod(thisObj, changeDriverVersionStringNa, DriverVersionStringNa);
	
	// Conversione variabili
	jstring DriverNameNa;
	DriverNameNa = env->NewStringUTF(var_DriverName);

	// Trova l'IDmetodo del metodo "setNaDriverName", che prende String come argomento e ritorna void
	jmethodID changeDriverNameNa = env->GetMethodID(cls, "setNaDriverName", "(Ljava/lang/String;)V");
	if (NULL == changeDriverNameNa) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setNaDriverName"
	env->CallVoidMethod(thisObj, changeDriverNameNa, DriverNameNa);
	
	// Conversione variabili
	jstring DriverDescriptionNa;
	DriverDescriptionNa = env->NewStringUTF(var_DriverDescription);

	// Trova l'IDmetodo del metodo "setNaDriverDescription", che prende String come argomento e ritorna void
	jmethodID changeDriverDescriptionNa = env->GetMethodID(cls, "setNaDriverDescription", "(Ljava/lang/String;)V");
	if (NULL == changeDriverDescriptionNa) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setNaDriverDescription"
	env->CallVoidMethod(thisObj, changeDriverDescriptionNa, DriverDescriptionNa);
	
	// Conversione variabili
	jstring DriverProviderNa;
	DriverProviderNa = env->NewStringUTF(var_DriverProvider);

	// Trova l'IDmetodo del metodo "setNaDriverProvider", che prende String come argomento e ritorna void
	jmethodID changeDriverProviderNa = env->GetMethodID(cls, "setNaDriverProvider", "(Ljava/lang/String;)V");
	if (NULL == changeDriverProviderNa) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setNaDriverProvider"
	env->CallVoidMethod(thisObj, changeDriverProviderNa, DriverProviderNa);

	// Conversione variabili
	jstring ComponentIDNa;
	ComponentIDNa = env->NewStringUTF(var_ComponentID);

	// Trova l'IDmetodo del metodo "setNaComponentID", che prende String come argomento e ritorna void
	jmethodID changeComponentIDNa = env->GetMethodID(cls, "setNaComponentID", "(Ljava/lang/String;)V");
	if (NULL == changeComponentIDNa) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setNaComponentID"
	env->CallVoidMethod(thisObj, changeComponentIDNa, ComponentIDNa);
	
	// Conversione variabili
	jstring AvailabilityNa;
	AvailabilityNa = env->NewStringUTF(var_Availability);

	// Trova l'IDmetodo del metodo "setNaAvailability", che prende String come argomento e ritorna void
	jmethodID changeAvailabilityNa = env->GetMethodID(cls, "setNaAvailability", "(Ljava/lang/String;)V");
	if (NULL == changeAvailabilityNa) return;

	//Crea la variabile di tipo jni e Utilizza il metodo "setNaAvailability"
	env->CallVoidMethod(thisObj, changeAvailabilityNa, AvailabilityNa);

	/*--------------------------------------------------------------------------------------------------------------*/

	//Connessione alla LOCAL MACHINE
	CComPtr< IWbemServices > se;
	servizio = loc->ConnectServer(L"root\\cimv2", NULL, NULL, NULL, WBEM_FLAG_CONNECT_USE_MAX_WAIT, NULL, NULL, &se);

	//Controllo errori sulla connessione alla LOCAL MACHINE
	if (FAILED(servizio))
	{
		std::cout << "Could not connect. Error code = 0x"
			<< std::hex << servizio << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//QUERY AT Win32_NetworkAdapter PROVIDER
	CComPtr< IEnumWbemClassObject > enumeratore;
	query = se->ExecQuery(L"WQL", L"SELECT * FROM Win32_NetworkAdapterConfiguration", WBEM_FLAG_FORWARD_ONLY, NULL, &enumeratore);

	//Controllo errori sulla query
	if (FAILED(query))
	{
		std::cout << "Query as failed. Error code = 0x"
			<< std::hex << query << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}

	//Lettura della query
	ULONG retur;
	CComPtr< IWbemClassObject > mobb;
	reading = enumeratore->Next(WBEM_INFINITE, 1L, &mobb, &retur);

	//Controllo sulla creazione della struttura ospitante dei dati raccolti tramite la query
	if (FAILED(reading))
	{
		std::cout << "Could not read query. Error code = 0x"
			<< std::hex << reading << std::endl;
		CoUninitialize();
		return;      // Program has failed.
	}


}