--------------------------------------------------------
--  Fichier créé - mardi-novembre-02-2021   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Table GESTION_PERSONNEL
--------------------------------------------------------

  CREATE TABLE "SYSTEM"."GESTION_PERSONNEL" 
   (	"CIN" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"AGE" NUMBER, 
	"SALAIRE" FLOAT(126), 
	"NUM_TEL" NUMBER
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into SYSTEM.GESTION_PERSONNEL
SET DEFINE OFF;
