DROP TABLE IF EXISTS `sys_usergrp`;
CREATE TABLE `sys_usergrp` (`ID_User` int(11) NOT NULL,`ID_Group` int(11) NOT NULL);

DROP TABLE IF EXISTS `worker`;
CREATE TABLE `worker` (
  `ID` AUTOINC,
  `Code` varchar(45) NOT NULL,
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
);

DROP TABLE IF EXISTS `qualification`;
CREATE TABLE `qualification` (
  `ID` AUTOINC,
  `Name` varchar(45) NOT NULL,
  `Deleted` tinyint(4) DEFAULT 0,
  PRIMARY KEY (`ID`)
);

DROP TABLE IF EXISTS `sys_uinsobjects`;
CREATE TABLE `sys_uinsobjects` (
  `NameObject` varchar(50) NOT NULL,
  `UIN` int(11) NOT NULL,
  PRIMARY KEY (`NameObject`,`UIN`)
);

DROP TABLE IF EXISTS `sys_usergroup`;
CREATE TABLE `sys_usergroup` (
  `ID` AUTOINC,
  `GroupName` varchar(45) DEFAULT NULL,
  `Blocked` tinyint(4) DEFAULT '0',
  `Deleted` tinyint(4) DEFAULT '0',
  PRIMARY KEY (`ID`)
);

DROP TABLE IF EXISTS `sys_userright`;
CREATE TABLE `sys_userright` (
  `IDObj` AUTOINC,
  `Object_type` tinyint(3) NOT NULL,
  `ObjectUIN` int(11) NOT NULL,
  `SubObjectUIN` int(11) NOT NULL,
  `Value` int(5) DEFAULT NULL,
  PRIMARY KEY (`IDObj`,`Object_type`,`ObjectUIN`,`SubObjectUIN`)
);

DROP TABLE IF EXISTS `sys_usersrole`;
CREATE TABLE `sys_usersrole` (
  `Name` varchar(45) NOT NULL,
  `RoleName` varchar(45) NOT NULL,
  `IDRoleUser` tinyint(4) DEFAULT '1',
  PRIMARY KEY (`Name`)
);

DROP TABLE IF EXISTS `sys_users`;
CREATE TABLE `sys_users` (
  `ID` AUTOINC,
  `UserName` varchar(45) NOT NULL,
  `UserPassword` varchar(128) NOT NULL,
  `RealUserName` varchar(45) NOT NULL,
  `Blocked` tinyint(4) DEFAULT '0',
  `Deleted` tinyint(4) DEFAULT '0',
  `IDRoleUser` tinyint(4) DEFAULT '0',
  PRIMARY KEY (`ID`)
);

DROP TABLE IF EXISTS `sys_usergrp`;
CREATE TABLE `sys_usergrp` (
  `ID_User` int(11) NOT NULL,
  `ID_Group` int(11) NOT NULL
);

DROP TABLE IF EXISTS `worker`;
CREATE TABLE `worker` (
  `ID` AUTOINC,
  `Code` varchar(45) NOT NULL,
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
);

DROP TABLE IF EXISTS `qualification`;
CREATE TABLE `qualification` (
  `ID` AUTOINC,
  `Name` varchar(45) NOT NULL,
  `Deleted` tinyint(4) DEFAULT 0,
  PRIMARY KEY (`ID`)
);

DROP TABLE IF EXISTS `sys_uinsobjects`;
CREATE TABLE `sys_uinsobjects` (
  `NameObject` varchar(50) NOT NULL,
  `UIN` int(11) NOT NULL,
  PRIMARY KEY (`NameObject`,`UIN`)
);

DROP TABLE IF EXISTS `sys_usergroup`;
CREATE TABLE `sys_usergroup` (
  `ID` AUTOINC,
  `GroupName` varchar(45) DEFAULT NULL,
  `Blocked` tinyint(4) DEFAULT '0',
  `Deleted` tinyint(4) DEFAULT '0',
  PRIMARY KEY (`ID`)
);

DROP TABLE IF EXISTS `sys_userright`;
CREATE TABLE `sys_userright` (
  `IDObj` AUTOINC,
  `Object_type` tinyint(3) NOT NULL,
  `ObjectUIN` int(11) NOT NULL,
  `SubObjectUIN` int(11) NOT NULL,
  `Value` int(5) DEFAULT NULL,
  PRIMARY KEY (`IDObj`,`Object_type`,`ObjectUIN`,`SubObjectUIN`)
);

DROP TABLE IF EXISTS `sys_usersrole`;
CREATE TABLE `sys_usersrole` (
  `Name` varchar(45) NOT NULL,
  `RoleName` varchar(45) NOT NULL,
  `IDRoleUser` tinyint(4) DEFAULT '1',
  PRIMARY KEY (`Name`)
);

DROP TABLE IF EXISTS `sys_users`;
CREATE TABLE `sys_users` (
  `ID` AUTOINC,
  `UserName` varchar(45) NOT NULL,
  `UserPassword` varchar(128) NOT NULL,
  `RealUserName` varchar(45) NOT NULL,
  `Blocked` tinyint(4) DEFAULT '0',
  `Deleted` tinyint(4) DEFAULT '0',
  `IDRoleUser` tinyint(4) DEFAULT '0',
  PRIMARY KEY (`ID`)
);

INSERT INTO `qualification` VALUES (1,'Администратор',0);
INSERT INTO `qualification` VALUES (2,'Мастер-универсал',0);
INSERT INTO `qualification` VALUES (3,'Бухгалтер',0);
INSERT INTO `qualification` VALUES (4,'Мастер',0);
INSERT INTO `qualification` VALUES (5,'Кладовщик',0);

INSERT INTO `sys_uinsobjects` VALUES ('admins',100);
INSERT INTO `sys_uinsobjects` VALUES ('sys_users',1);
INSERT INTO `sys_usergroup` VALUES (1,'Администраторы',0,0);
INSERT INTO `sys_userright` VALUES (1,1,1,0,111);
INSERT INTO `sys_userright` VALUES (1,2,100,0,1);
INSERT INTO `sys_usersrole` VALUES ('admin','Администратор',1);
INSERT INTO `sys_usersrole` VALUES ('kassir','Кассир',2);
INSERT INTO `sys_usersrole` VALUES ('operator','Оператор',3);
INSERT INTO `sys_usersrole` VALUES ('user','Пользователь',4);
INSERT INTO `sys_users` VALUES (1,'admin','da39a3ee5e6b4b0d3255bfef95601890afd80709','Администратор',0,0,1);
INSERT INTO `sys_users` VALUES (2,'user','da39a3ee5e6b4b0d3255bfef95601890afd80709','Пользователь',0,0,4);