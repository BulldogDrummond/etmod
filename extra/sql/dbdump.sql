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
INSERT INTO `map_stats` VALUES ('oasis','0.359947','0.906862',8,'[BOT] Mungri'),('battery','0.182814','0.936812',20,'Drummond'),('goldrush','0.043948','0.982371',12,'[BOT] Ryver'),('radar','0.020976','0.992053',3,'[BOT] Zarna');
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
  UNIQUE KEY `guid` (`guid`),
  UNIQUE KEY `name` (`name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Shrubbot Player XP Data';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `player_xp`
--

LOCK TABLES `player_xp` WRITE;
/*!40000 ALTER TABLE `player_xp` DISABLE KEYS */;
INSERT INTO `player_xp` VALUES ('ECEBD89CADE1E45BBD5F626091963F7E','Drummond',1360169188,'205.000000','295.500000','000.000000','000.000000','450.000000','108.000000','102.500000','1.093243','0.023170','0.503681','0.871211');
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
INSERT INTO `server_status` VALUES (1,'DB_Test','OK',1),(2,'current_map','None',1),(3,'rating','2.572208',1),(4,'rating_variance','0.974724',1),(5,'distance_rating','0.000000',1),(6,'distance_variance','0.000000',1);
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

-- Dump completed on 2013-02-07  7:27:42
