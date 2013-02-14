-- MySQL dump 10.13  Distrib 5.1.66, for debian-linux-gnu (i486)
--
-- Host: localhost    Database: etlegacy
-- ------------------------------------------------------
-- Server version	5.1.66-0ubuntu0.10.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `map_stats`
--

DROP TABLE IF EXISTS `map_stats`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `map_stats` (
  `map_name` varchar(40) NOT NULL,
  `rating` decimal(7,6) unsigned zerofill NOT NULL,
  `rating_variance` decimal(7,6) unsigned zerofill NOT NULL,
  `spree_record` tinyint(4) NOT NULL,
  `spree_name` varchar(40) NOT NULL,
  UNIQUE KEY `map_name` (`map_name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Shrubbot Map Stat Data';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `map_stats`
--

LOCK TABLES `map_stats` WRITE;
/*!40000 ALTER TABLE `map_stats` DISABLE KEYS */;
INSERT INTO `map_stats` VALUES ('ge_temple_v2a','0.000000','0.968895',7,'Keller [B]'),('goldrush','0.041658','0.982572',13,'Cullen'),('radar','0.026536','0.988821',8,'Weissmann [B]'),('et_beach','0.000000','1.000000',0,''),('crevasse_pe','0.000000','1.000000',0,''),('braundorf_final','0.000000','1.000000',0,''),('navarone','0.000000','1.000000',0,''),('trmfght_beta2','0.000000','1.000000',0,''),('oasis','0.403761','0.892293',13,'Malone'),('et_mor_pro','0.337091','0.936888',17,'Cullen'),('citadel_obj','0.050722','0.980090',14,'Cullen'),('battery','0.033226','0.986085',7,'Bauer [B]');
/*!40000 ALTER TABLE `map_stats` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `player_levels`
--

DROP TABLE IF EXISTS `player_levels`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `player_levels` (
  `pl_level` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Level ID',
  `pl_name` varchar(40) NOT NULL COMMENT 'Level Name',
  `pl_flags` varchar(50) NOT NULL COMMENT 'Permission Flags',
  `pl_greeting` varchar(50) DEFAULT NULL COMMENT 'Greeting Text',
  `pl_greeting_sound` varchar(80) DEFAULT NULL COMMENT 'Greeting Sound Resource',
  PRIMARY KEY (`pl_level`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COMMENT='Shrubbot Player Level Data';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `player_levels`
--

LOCK TABLES `player_levels` WRITE;
/*!40000 ALTER TABLE `player_levels` DISABLE KEYS */;
INSERT INTO `player_levels` VALUES (0,'Prole','CiBhaPzI',NULL,NULL),(1,'Level 1','CiBhaPzIW1','Level 1 [n] ^7just connected',NULL),(2,'Level 2','CiBhaPzIW1mx','Level 2 [n] ^7just connected',NULL),(3,'Level 3','CiBhaPzIW1mxpZSAURKrwlLdX259','Level 3 [n] ^7just connected',NULL),(4,'Level 4','CiBhaPzIW1mxpZSAURKrwlLdX259kbcVNn34678','Level 4 [n] ^7just connected',NULL),(5,'Level 5','*','Level 5 [n] ^7just connected',NULL);
/*!40000 ALTER TABLE `player_levels` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `player_xp`
--

DROP TABLE IF EXISTS `player_xp`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `player_xp` (
  `guid` varchar(32) NOT NULL,
  `name` varchar(40) NOT NULL,
  `time` bigint(20) unsigned NOT NULL DEFAULT '0',
  `skill0` decimal(9,6) unsigned zerofill NOT NULL DEFAULT '000.000000',
  `skill1` decimal(9,6) unsigned zerofill NOT NULL DEFAULT '000.000000',
  `skill2` decimal(9,6) unsigned zerofill NOT NULL DEFAULT '000.000000',
  `skill3` decimal(9,6) unsigned zerofill NOT NULL DEFAULT '000.000000',
  `skill4` decimal(9,6) unsigned zerofill NOT NULL DEFAULT '000.000000',
  `skill5` decimal(9,6) unsigned zerofill NOT NULL DEFAULT '000.000000',
  `skill6` decimal(9,6) unsigned zerofill NOT NULL DEFAULT '000.000000',
  `kill_rating` decimal(7,6) unsigned zerofill NOT NULL DEFAULT '0.000000',
  `kill_variance` decimal(7,6) unsigned zerofill NOT NULL DEFAULT '0.000000',
  `rating` decimal(7,6) unsigned zerofill NOT NULL DEFAULT '0.000000',
  `rating_variance` decimal(7,6) unsigned zerofill NOT NULL DEFAULT '0.000000',
  `mutetime` bigint(20) NOT NULL DEFAULT '-1',
  `hits` int(10) unsigned NOT NULL DEFAULT '0',
  `team_hits` int(10) unsigned NOT NULL DEFAULT '0',
  `team` int(10) unsigned NOT NULL DEFAULT '0',
  `teamName` varchar(10) NOT NULL,
  `rank` int(10) unsigned DEFAULT '0',
  `rankName` varchar(30) DEFAULT NULL,
  UNIQUE KEY `guid` (`guid`),
  KEY `name` (`name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Shrubbot Player XP Data';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `player_xp`
--

LOCK TABLES `player_xp` WRITE;
/*!40000 ALTER TABLE `player_xp` DISABLE KEYS */;
INSERT INTO `player_xp` VALUES ('OMNIBOT0100000000000000000000000','Bauer [B]',1360814461,'131.000000','169.500000','043.000000','022.000000','264.000000','005.000000','015.000000','0.301110','0.021554','0.000000','0.833987',0,29,2,1,'Axis',5,'Hauptmann'),('OMNIBOT0200000000000000000000000','Smith [B]',1360814461,'176.000000','023.000000','037.000000','000.000000','328.000000','000.000000','020.000000','0.000000','0.021349','0.471325','0.815438',0,15,4,2,'Allies',5,'Captain'),('OMNIBOT0300000000000000000000000','Vogel [B]',1360814461,'204.000000','090.000000','070.000000','000.000000','287.000000','011.000000','051.500000','0.176567','0.024553','0.000000','0.814781',0,14,2,1,'Axis',5,'Hauptmann'),('OMNIBOT0400000000000000000000000','Rowan [B]',1360814461,'173.000000','203.000000','015.000000','007.000000','240.000000','003.000000','000.000000','0.000000','0.022598','0.483205','0.813654',0,19,0,2,'Allies',6,'Major'),('OMNIBOT0500000000000000000000000','Weissmann [B]',1360814461,'172.000000','079.500000','046.000000','006.000000','362.000000','012.000000','010.000000','0.270672','0.020138','0.000000','0.833864',0,48,2,1,'Axis',5,'Hauptmann'),('OMNIBOT0600000000000000000000000','Kowalski [B]',1360814461,'142.000000','016.000000','000.000000','055.000000','294.000000','000.000000','000.000000','0.000000','0.022184','0.471487','0.808782',0,43,0,2,'Allies',5,'Captain'),('OMNIBOT0700000000000000000000000','Bohm [B]',1360814461,'180.000000','078.500000','065.000000','006.000000','302.000000','016.000000','000.000000','0.000000','0.022081','0.000000','0.827577',0,33,0,1,'Axis',5,'Hauptmann'),('OMNIBOT0800000000000000000000000','Miller [B]',1360814461,'182.000000','010.000000','094.000000','002.000000','294.000000','000.000000','030.000000','0.000000','0.025212','0.467309','0.813578',0,22,1,2,'Allies',5,'Captain'),('OMNIBOT0900000000000000000000000','Fischer [B]',1360814461,'172.000000','057.000000','096.000000','022.000000','276.000000','004.000000','018.500000','0.059188','0.024145','0.000000','0.824788',0,36,1,1,'Axis',5,'Hauptmann'),('OMNIBOT1000000000000000000000000','Barton [B]',1360814461,'206.000000','094.000000','022.000000','000.000000','334.000000','000.000000','125.000000','0.010360','0.022675','0.465976','0.813569',0,49,11,2,'Allies',5,'Captain'),('OMNIBOT1100000000000000000000000','Lorenz [B]',1360814461,'149.000000','076.000000','053.000000','025.000000','326.000000','000.000000','074.000000','0.179362','0.022856','0.000000','0.830119',0,48,2,1,'Axis',5,'Hauptmann'),('OMNIBOT1800000000000000000000000','Washington [B]',1360813979,'000.000000','000.000000','000.000000','004.000000','000.000000','000.000000','000.000000','0.000000','0.839121','0.013066','0.999834',0,0,0,2,'Allies',0,'Private'),('ECEBD89CADE1E45BBD5F626091963F7E','Malone',1360764427,'174.000000','068.500000','000.000000','000.000000','402.000000','034.000000','037.500000','1.763440','0.044719','0.206466','0.890772',0,40,3,0,'',0,NULL),('OMNIBOT1300000000000000000000000','Keller [B]',1360814461,'177.000000','203.000000','000.000000','000.000000','253.000000','015.000000','035.000000','0.001030','0.022874','0.000000','0.827161',0,40,7,1,'Axis',6,'Major'),('OMNIBOT1700000000000000000000000','Johnson [B]',1360814461,'178.000000','135.500000','013.000000','000.000000','333.000000','000.000000','032.500000','0.000000','0.021847','0.000000','0.838566',0,33,3,2,'Allies',5,'Captain'),('OMNIBOT1400000000000000000000000','Corman [B]',1360814461,'168.000000','072.500000','069.000000','000.000000','261.000000','000.000000','000.000000','0.000000','0.024409','0.428866','0.833051',0,22,0,2,'Allies',5,'Captain'),('OMNIBOT1200000000000000000000000','Callahan [B]',1360814461,'140.000000','106.000000','066.000000','017.000000','252.000000','003.000000','000.000000','0.000000','0.023575','0.466207','0.820569',0,17,0,2,'Allies',5,'Captain'),('OMNIBOT1600000000000000000000000','Huber [B]',1360814461,'156.000000','045.000000','075.000000','010.000000','325.000000','010.000000','000.000000','0.069892','0.022991','0.000000','0.822729',0,34,0,1,'Axis',5,'Hauptmann'),('OMNIBOT1500000000000000000000000','Schmitt [B]',1360814461,'204.000000','094.000000','033.000000','033.000000','313.000000','006.000000','020.000000','0.053992','0.021489','0.000000','0.823383',0,53,0,1,'Axis',5,'Hauptmann'),('BCB83A79E0AD66C998BB33B23E38BAB9','Cullen',1360814475,'183.000000','144.500000','000.000000','000.000000','376.000000','082.000000','020.000000','1.263942','0.034059','0.274373','0.906566',0,60,0,2,'Allies',6,'Major');
/*!40000 ALTER TABLE `player_xp` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `server_status`
--

DROP TABLE IF EXISTS `server_status`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `server_status` (
  `ss_uid` mediumint(8) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Unique Row ID',
  `ss_key` varchar(20) NOT NULL COMMENT 'Status Key',
  `ss_val` varchar(40) NOT NULL COMMENT 'Status Value',
  `ss_persist` smallint(6) NOT NULL DEFAULT '0' COMMENT 'Set to 1 to retain in database',
  PRIMARY KEY (`ss_uid`),
  UNIQUE KEY `ss_key` (`ss_key`)
) ENGINE=MyISAM AUTO_INCREMENT=7 DEFAULT CHARSET=utf8 COMMENT='Server Status';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `server_status`
--

LOCK TABLES `server_status` WRITE;
/*!40000 ALTER TABLE `server_status` DISABLE KEYS */;
INSERT INTO `server_status` VALUES (1,'DB_Test','OK',1),(2,'current_map','None',1),(3,'rating','0.000000',1),(4,'rating_variance','0.000000',1),(5,'distance_rating','0.000000',1),(6,'distance_variance','0.000000',1);
/*!40000 ALTER TABLE `server_status` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2013-02-13 23:02:58
