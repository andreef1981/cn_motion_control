
#ifndef _PP_PROJ_H_
#define _PP_PROJ_H_
//***********************************************************************************
// C header for accessing PMAC Global, CSGlobal, Ptr vars
// _PPScriptMode_ for Pmac Script like access global & csglobal
// global Mypvar - access with "Mypvar"
// global Myparray(32) - access with "Myparray(i)"
// csglobal Myqvar - access with "Myqvar(i)" where "i" is Coord #
// csglobal Myqarray(16) - access with "Myqvar(i,j)" where "j" is index
// _EnumMode_ for Pmac enum data type checking on Set & Get global functions
// Example
// global Mypvar
// csglobal Myqvar
// "SetGlobalVar(Myqvar, data)" will give a compile error because its a csglobal var.
// "SetCSGlobalVar(Mypvar, data)" will give a compile error because its a global var.
//************************************************************************************

#ifdef _PPScriptMode_
enum globalP {_globalP_=-1};
enum globalParray {_globalParray_=-1};
enum csglobalQ {_csglobalQ_=-1};
enum csglobalQarray {_csglobalQarray_=-1};

enum ptrM {_ptrM_=-1
,Motor7UserFlag=8192
,Motor10UserFlag=8193
,Motor11UserFlag=8194
,Motor16UserFlag=8195
,Motor17UserFlag=8196
,Motor6PlusFlag=8197
,Motor6MinusFlag=8198
,Input1=8199
,Input2=8200
,Input3=8201
,Input4=8202
,Input5=8203
,Input6=8204
,Input7=8205
,Input8=8206
,Input9=8207
,Input10=8208
,Input11=8209
,Input12=8210
,Input13=8211
,Input14=8212
,Input15=8213
,Input16=8214
,Input17=8215
,Input18=8216
,Input19=8217
,Input20=8218
,Input21=8219
,Input22=8220
,Input23=8221
,Input24=8222};
enum ptrMarray {_ptrMarray_=-1};
#define	DesiredPosition(i)	pshm->Coord[i%MAX_COORDS].Q[0]
#define	PosCounter(i)	pshm->Coord[i%MAX_COORDS].Q[1024]
#define	Checker(i)	pshm->Coord[i%MAX_COORDS].Q[1025]
#define	actualPos(i)	pshm->Coord[i%MAX_COORDS].Q[1026]
#define	PlusInCounter(i)	pshm->Coord[i%MAX_COORDS].Q[1027]
#define	PlusOutCounter(i)	pshm->Coord[i%MAX_COORDS].Q[1028]
#define	MinusInCounter(i)	pshm->Coord[i%MAX_COORDS].Q[1029]
#define	MinusOutCounter(i)	pshm->Coord[i%MAX_COORDS].Q[1030]
void SetEnumGlobalVar(enum globalP var, double data)
{
  pshm->P[var] = data;
}

double GetEnumGlobalVar(enum globalP var)
{
  return pshm->P[var];
}

void SetEnumGlobalArrayVar(enum globalParray var, unsigned index, double data)
{
  pshm->P[(var + index)%MAX_P] = data;
}

double GetEnumGlobalArrayVar(enum globalParray var, unsigned index)
{
  return pshm->P[(var + index)%MAX_P];
}

void SetEnumCSGlobalVar(enum csglobalQ var, unsigned cs, double data)
{
  pshm->Coord[cs % MAX_COORDS].Q[var] = data;
}

double GetEnumCSGlobalVar(enum csglobalQ var, unsigned cs)
{
  return pshm->Coord[cs % MAX_COORDS].Q[var];
}

void SetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs, double data)
{
  pshm->Coord[cs % MAX_COORDS].Q[(var + index)%MAX_Q] = data;
}

double GetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs)
{
  return pshm->Coord[cs % MAX_COORDS].Q[(var + index)%MAX_Q];
}

void SetEnumPtrVar(enum ptrM var, double data)
{
  im_write(pshm->Mdef + var, data, &pshm->Ldata);
}

double GetEnumPtrVar(enum ptrM var)
{
  return im_read(pshm->Mdef + var, &pshm->Ldata);
}

void SetEnumPtrArrayVar(enum ptrMarray var, unsigned index, double data)
{
  im_write(pshm->Mdef + ((var + index)%MAX_M), data, &pshm->Ldata);
}

double GetEnumPtrArrayVar(enum ptrMarray var, unsigned index)
{
  return im_read(pshm->Mdef + ((var + index)%MAX_M), &pshm->Ldata);
}

#define SetGlobalVar(i, x)              SetEnumGlobalVar(i, x)
#define SetGlobalArrayVar(i, j, x)      SetEnumGlobalArrayVar(i, j, x)
#define GetGlobalVar(i)                 GetEnumGlobalVar(i)
#define GetGlobalArrayVar(i, j)         GetEnumGlobalArrayVar(i, j)

#define SetCSGlobalVar(i, j, x)         SetEnumCSGlobalVar(i, j, x)
#define SetCSGlobalArrayVar(i, j, k, x) SetEnumCSGlobalArrayVar(i, j, k, x)
#define GetCSGlobalVar(i, j)            GetEnumCSGlobalVar(i, j)
#define GetCSGlobalArrayVar(i, j, k)    GetEnumCSGlobalArrayVar(i, j, k)

#define SetPtrVar(i, x)                 SetEnumPtrVar(i, x)
#define SetPtrArrayVar(i, j, x)         SetEnumPtrArrayVar(i, j, x)
#define GetPtrVar(i)                    GetEnumPtrVar(i)
#define GetPtrArrayVar(i, j)            GetEnumPtrArrayVar(i, j)
// end of #ifdef _PPScriptMode_
#else
#ifdef _EnumMode_
enum globalP {_globalP_=-1};
enum globalParray {_globalParray_=-1};
enum csglobalQ {_csglobalQ_=-1
,DesiredPosition=0
,PosCounter=1024
,Checker=1025
,actualPos=1026
,PlusInCounter=1027
,PlusOutCounter=1028
,MinusInCounter=1029
,MinusOutCounter=1030};
enum csglobalQarray {_csglobalQarray_=-1};
enum ptrM {_ptrM_=-1
,Motor7UserFlag=8192
,Motor10UserFlag=8193
,Motor11UserFlag=8194
,Motor16UserFlag=8195
,Motor17UserFlag=8196
,Motor6PlusFlag=8197
,Motor6MinusFlag=8198
,Input1=8199
,Input2=8200
,Input3=8201
,Input4=8202
,Input5=8203
,Input6=8204
,Input7=8205
,Input8=8206
,Input9=8207
,Input10=8208
,Input11=8209
,Input12=8210
,Input13=8211
,Input14=8212
,Input15=8213
,Input16=8214
,Input17=8215
,Input18=8216
,Input19=8217
,Input20=8218
,Input21=8219
,Input22=8220
,Input23=8221
,Input24=8222};
enum ptrMarray {_ptrMarray_=-1};
void SetEnumGlobalVar(enum globalP var, double data)
{
  pshm->P[var] = data;
}

double GetEnumGlobalVar(enum globalP var)
{
  return pshm->P[var];
}

void SetEnumGlobalArrayVar(enum globalParray var, unsigned index, double data)
{
  pshm->P[(var + index)%MAX_P] = data;
}

double GetEnumGlobalArrayVar(enum globalParray var, unsigned index)
{
  return pshm->P[(var + index)%MAX_P];
}

void SetEnumCSGlobalVar(enum csglobalQ var, unsigned cs, double data)
{
  pshm->Coord[cs % MAX_COORDS].Q[var] = data;
}

double GetEnumCSGlobalVar(enum csglobalQ var, unsigned cs)
{
  return pshm->Coord[cs % MAX_COORDS].Q[var];
}

void SetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs, double data)
{
  pshm->Coord[cs % MAX_COORDS].Q[(var + index)%MAX_Q] = data;
}

double GetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs)
{
  return pshm->Coord[cs % MAX_COORDS].Q[(var + index)%MAX_Q];
}

void SetEnumPtrVar(enum ptrM var, double data)
{
  im_write(pshm->Mdef + var, data, &pshm->Ldata);
}

double GetEnumPtrVar(enum ptrM var)
{
  return im_read(pshm->Mdef + var, &pshm->Ldata);
}

void SetEnumPtrArrayVar(enum ptrMarray var, unsigned index, double data)
{
  im_write(pshm->Mdef + ((var + index)%MAX_M), data, &pshm->Ldata);
}

double GetEnumPtrArrayVar(enum ptrMarray var, unsigned index)
{
  return im_read(pshm->Mdef + ((var + index)%MAX_M), &pshm->Ldata);
}

#define SetGlobalVar(i, x)              SetEnumGlobalVar(i, x)
#define SetGlobalArrayVar(i, j, x)      SetEnumGlobalArrayVar(i, j, x)
#define GetGlobalVar(i)                 GetEnumGlobalVar(i)
#define GetGlobalArrayVar(i, j)         GetEnumGlobalArrayVar(i, j)

#define SetCSGlobalVar(i, j, x)         SetEnumCSGlobalVar(i, j, x)
#define SetCSGlobalArrayVar(i, j, k, x) SetEnumCSGlobalArrayVar(i, j, k, x)
#define GetCSGlobalVar(i, j)            GetEnumCSGlobalVar(i, j)
#define GetCSGlobalArrayVar(i, j, k)    GetEnumCSGlobalArrayVar(i, j, k)

#define SetPtrVar(i, x)                 SetEnumPtrVar(i, x)
#define SetPtrArrayVar(i, j, x)         SetEnumPtrArrayVar(i, j, x)
#define GetPtrVar(i)                    GetEnumPtrVar(i)
#define GetPtrArrayVar(i, j)            GetEnumPtrArrayVar(i, j)
// end of #ifdef _EnumMode_
#else
// ***** Standard default mode *****
#define DesiredPosition 0
#define PosCounter 1024
#define Checker 1025
#define actualPos 1026
#define PlusInCounter 1027
#define PlusOutCounter 1028
#define MinusInCounter 1029
#define MinusOutCounter 1030
#define Motor7UserFlag 8192
#define Motor10UserFlag 8193
#define Motor11UserFlag 8194
#define Motor16UserFlag 8195
#define Motor17UserFlag 8196
#define Motor6PlusFlag 8197
#define Motor6MinusFlag 8198
#define Input1 8199
#define Input2 8200
#define Input3 8201
#define Input4 8202
#define Input5 8203
#define Input6 8204
#define Input7 8205
#define Input8 8206
#define Input9 8207
#define Input10 8208
#define Input11 8209
#define Input12 8210
#define Input13 8211
#define Input14 8212
#define Input15 8213
#define Input16 8214
#define Input17 8215
#define Input18 8216
#define Input19 8217
#define Input20 8218
#define Input21 8219
#define Input22 8220
#define Input23 8221
#define Input24 8222
#endif
#endif
#endif //_PP_PROJ_H_
