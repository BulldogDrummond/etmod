-- -------------------------------------------------------------------
-- ET Database
-- -------------------------------------------------------------------

-- Table      : player_levels
-- Filename   : etlegacy/player_levels.sql
-- DB Version : 1.0

-- This  file is  free software;  as a  special exception  the  author
-- gives  unlimited permission  to copy and/or distribute it,  with or
-- without modification, as long as this notice is preserved.

-- This program is distributed in the hope that it will be useful, but
-- WITHOUT ANY WARRANTY,  to the extent permitted by law; without even
-- the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
-- PURPOSE.

-- -------------------------------------------------------------------

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
INSERT INTO `player_levels` (`pl_level`, `pl_name`, `pl_flags`, `pl_greeting`, `pl_greeting_sound`) VALUES (0,'Prole','CiBhaPzI',NULL,NULL);
INSERT INTO `player_levels` (`pl_level`, `pl_name`, `pl_flags`, `pl_greeting`, `pl_greeting_sound`) VALUES (1,'Level 1','CiBhaPzIW1','Level 1 [n] ^7just connected',NULL);
INSERT INTO `player_levels` (`pl_level`, `pl_name`, `pl_flags`, `pl_greeting`, `pl_greeting_sound`) VALUES (2,'Level 2','CiBhaPzIW1mx','Level 2 [n] ^7just connected',NULL);
INSERT INTO `player_levels` (`pl_level`, `pl_name`, `pl_flags`, `pl_greeting`, `pl_greeting_sound`) VALUES (3,'Level 3','CiBhaPzIW1mxpZSAURKrwlLdX259','Level 3 [n] ^7just connected',NULL);
INSERT INTO `player_levels` (`pl_level`, `pl_name`, `pl_flags`, `pl_greeting`, `pl_greeting_sound`) VALUES (4,'Level 4','CiBhaPzIW1mxpZSAURKrwlLdX259kbcVNn34678','Level 4 [n] ^7just connected',NULL);
INSERT INTO `player_levels` (`pl_level`, `pl_name`, `pl_flags`, `pl_greeting`, `pl_greeting_sound`) VALUES (5,'Level 5','*','Level 5 [n] ^7just connected',NULL);
/*!40000 ALTER TABLE `player_levels` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- End-Of-File: player_levels.sql

