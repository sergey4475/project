DROP TABLE IF EXISTS `sys_usergrp`;
CREATE TABLE `sys_usergrp` (
  `ID_User` int(11) NOT NULL,
  `ID_Group` int(11) NOT NULL
)  DEFAULT CHARSET=utf8;
--
-- Table structure for table `worker`
--

DROP TABLE IF EXISTS `worker`;
CREATE TABLE `worker` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `Code` varchar(45) NOT NULL COMMENT 'Табельный номер',
  `FName` varchar(45) NOT NULL,
  `IName` varchar(45) NOT NULL,
  `OName` varchar(45) NOT NULL,
  `DateR` date DEFAULT NULL,
  `INN` varchar(12) DEFAULT NULL,
  `OGRN` varchar(20) DEFAULT NULL,
  `Address` text,
  `Phones` text,
  `SDate` date DEFAULT '0001-01-01',
  `EDate` date DEFAULT '0001-01-01',
  `Comments` text,
  `IsAdministrator` tinyint(4) DEFAULT NULL,
  `IDQualification` int(11) DEFAULT NULL,
  `Deleted` tinyint(4) DEFAULT '0',
  PRIMARY KEY (`ID`)
)  AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COMMENT='Сотрудники организаций';

--
-- Table structure for table `qualification`
--

DROP TABLE IF EXISTS `qualification`;
CREATE TABLE `qualification` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `Name` varchar(45) NOT NULL,
  `Deleted` tinyint(4) DEFAULT '0',
  PRIMARY KEY (`ID`)
)  AUTO_INCREMENT=6 DEFAULT CHARSET=utf8 COMMENT='Квалификации сотрудников';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `sys_uinsobjects`
--

DROP TABLE IF EXISTS `sys_uinsobjects`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `sys_uinsobjects` (
  `NameObject` varchar(50) NOT NULL,
  `UIN` int(11) NOT NULL,
  PRIMARY KEY (`NameObject`,`UIN`)
)  DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `sys_usergroup`
--

DROP TABLE IF EXISTS `sys_usergroup`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `sys_usergroup` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `GroupName` varchar(45) DEFAULT NULL,
  `Blocked` tinyint(4) DEFAULT '0',
  `Deleted` tinyint(4) DEFAULT '0',
  PRIMARY KEY (`ID`)
)  AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `sys_userright`
--

DROP TABLE IF EXISTS `sys_userright`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `sys_userright` (
  `IDObj` int(11) NOT NULL,
  `Object_type` tinyint(3) NOT NULL,
  `ObjectUIN` int(11) NOT NULL,
  `SubObjectUIN` int(11) NOT NULL,
  `Value` int(5) DEFAULT NULL,
  PRIMARY KEY (`IDObj`,`Object_type`,`ObjectUIN`,`SubObjectUIN`)
)  DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `sys_usersrole`
--

DROP TABLE IF EXISTS `sys_usersrole`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `sys_usersrole` (
  `Name` varchar(45) NOT NULL,
  `RoleName` varchar(45) NOT NULL,
  `IDRoleUser` tinyint(4) DEFAULT '1',
  PRIMARY KEY (`Name`)
)  DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `sys_users`
--

DROP TABLE IF EXISTS `sys_users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `sys_users` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `UserName` varchar(45) NOT NULL,
  `UserPassword` varchar(128) NOT NULL,
  `RealUserName` varchar(45) NOT NULL,
  `Blocked` tinyint(4) DEFAULT '0',
  `Deleted` tinyint(4) DEFAULT '0',
  `IDRoleUser` tinyint(4) DEFAULT '0',
  PRIMARY KEY (`ID`)
)  AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

LOCK TABLES `sys_usergrp` WRITE;
/*!40000 ALTER TABLE `sys_usergrp` DISABLE KEYS */;
/*!40000 ALTER TABLE `sys_usergrp` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping data for table `worker`
--

LOCK TABLES `worker` WRITE;
/*!40000 ALTER TABLE `worker` DISABLE KEYS */;
INSERT INTO `worker` VALUES (1,'0001','Иванчук','Петр','Григорьевич','1986-05-01',NULL,NULL,NULL,NULL,'2012-05-01','0001-01-01',NULL,NULL,NULL,0);
/*!40000 ALTER TABLE `worker` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping data for table `qualification`
--

LOCK TABLES `qualification` WRITE;
/*!40000 ALTER TABLE `qualification` DISABLE KEYS */;
INSERT INTO `qualification` VALUES (1,'Администратор',0),(2,'Мастер-универсал',0),(3,'Бухгалтер',0),(4,'Мастер',0),(5,'Кладовщик',0);
/*!40000 ALTER TABLE `qualification` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping data for table `sys_uinsobjects`
--

LOCK TABLES `sys_uinsobjects` WRITE;
/*!40000 ALTER TABLE `sys_uinsobjects` DISABLE KEYS */;
INSERT INTO `sys_uinsobjects` VALUES ('admins',100),('sys_users',1);
/*!40000 ALTER TABLE `sys_uinsobjects` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping data for table `sys_usergroup`
--

LOCK TABLES `sys_usergroup` WRITE;
/*!40000 ALTER TABLE `sys_usergroup` DISABLE KEYS */;
INSERT INTO `sys_usergroup` VALUES (1,'Администраторы',0,0);
/*!40000 ALTER TABLE `sys_usergroup` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping data for table `sys_userright`
--

LOCK TABLES `sys_userright` WRITE;
/*!40000 ALTER TABLE `sys_userright` DISABLE KEYS */;
INSERT INTO `sys_userright` VALUES (1,1,1,0,111),(1,2,100,0,1);
/*!40000 ALTER TABLE `sys_userright` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping data for table `sys_usersrole`
--

LOCK TABLES `sys_usersrole` WRITE;
/*!40000 ALTER TABLE `sys_usersrole` DISABLE KEYS */;
INSERT INTO `sys_usersrole` VALUES ('admin','Администратор',1),('kassir','Кассир',2),('operator','Оператор',3),('user','Пользователь',4);
/*!40000 ALTER TABLE `sys_usersrole` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping data for table `sys_users`
--

LOCK TABLES `sys_users` WRITE;
/*!40000 ALTER TABLE `sys_users` DISABLE KEYS */;
INSERT INTO `sys_users` VALUES (1,'admin','d033e22ae348aeb5660fc2140aec35850c4da997','Администратор',0,0,1),(2,'user','da39a3ee5e6b4b0d3255bfef95601890afd80709','Пользователь',0,0,4);
/*!40000 ALTER TABLE `sys_users` ENABLE KEYS */;
UNLOCK TABLES;