-- -------------------------------------------------------------------
-- ET Database
-- -------------------------------------------------------------------

-- Table      : player_xp
-- Filename   : etlegacy/player_xp.sql
-- DB Version : 1.0

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
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0100000000000000000000000','Kruger [B]',1361040574,'228.000000','183.000000','144.000000','000.000000','315.000000','020.000000','033.500000','0.131373','0.017740','0.000000','0.756991',0,0,0,1,'Axis',7,'Oberst');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0200000000000000000000000','Smith [B]',1361040574,'217.000000','153.500000','074.000000','002.000000','380.000000','000.000000','027.500000','0.000000','0.016422','0.376413','0.749535',0,0,0,2,'Allies',6,'Major');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0300000000000000000000000','Keller [B]',1361040574,'215.000000','061.500000','046.000000','001.000000','433.000000','019.000000','046.500000','0.095474','0.017426','0.000000','0.749228',0,0,0,1,'Axis',5,'Hauptmann');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0400000000000000000000000','Johnson [B]',1361040574,'183.000000','106.500000','042.000000','005.000000','373.000000','036.000000','007.500000','0.000000','0.017439','0.343260','0.754155',0,0,0,2,'Allies',5,'Captain');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0500000000000000000000000','Weissmann [B]',1361040574,'212.000000','068.000000','025.000000','052.000000','361.000000','031.000000','040.000000','0.126933','0.018976','0.000000','0.760224',0,0,0,1,'Axis',5,'Hauptmann');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0600000000000000000000000','Whittman [B]',1361040574,'204.000000','032.000000','031.000000','044.000000','391.000000','012.000000','009.000000','0.000000','0.017573','0.336645','0.742951',0,0,0,2,'Allies',5,'Captain');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0700000000000000000000000','Wolff [B]',1361040574,'211.000000','081.500000','026.000000','012.000000','426.000000','021.000000','039.000000','0.100919','0.016976','0.000000','0.774678',0,0,0,1,'Axis',5,'Hauptmann');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0800000000000000000000000','Peterson [B]',1361040574,'225.000000','233.500000','024.000000','001.000000','397.000000','000.000000','000.000000','0.000000','0.017691','0.380084','0.751644',0,0,0,2,'Allies',6,'Major');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0900000000000000000000000','Schneider [B]',1361040574,'260.000000','118.500000','021.000000','006.000000','399.000000','019.000000','057.000000','0.241947','0.019515','0.000000','0.764695',0,0,0,1,'Axis',5,'Hauptmann');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1000000000000000000000000','Hahn [B]',1361040574,'250.000000','098.000000','050.000000','002.000000','375.000000','006.000000','047.500000','0.000000','0.018294','0.189745','0.743807',0,0,0,1,'Axis',5,'Hauptmann');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1100000000000000000000000','Shaw [B]',1361040574,'167.000000','170.000000','068.000000','031.000000','404.000000','005.000000','000.000000','0.212019','0.016208','0.000000','0.767977',0,0,0,2,'Allies',6,'Major');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1800000000000000000000000','Stiker [B]',1361040586,'006.000000','000.000000','009.000000','000.000000','023.000000','000.000000','000.000000','0.000000','0.196582','0.084478','0.982912',0,0,0,2,'Allies',1,'Private 1st Class');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('ECEBD89CADE1E45BBD5F626091963F7E','Malone',1361041321,'999.999999','503.500000','000.000000','000.000000','999.999999','251.000000','981.000000','1.485693','0.007187','0.895931','0.617093',0,153,11,2,'Allies',8,'Brigadier General');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1300000000000000000000000','Callahan [B]',1361040574,'208.000000','011.500000','000.000000','170.000000','396.000000','012.000000','020.500000','0.000000','0.015215','0.000000','0.767777',0,0,0,2,'Allies',6,'Major');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1700000000000000000000000','Kowalski [B]',1361040574,'190.000000','084.500000','126.000000','013.000000','340.000000','002.000000','023.000000','0.000000','0.019729','0.000000','0.764533',0,0,0,2,'Allies',5,'Captain');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1400000000000000000000000','Schmitt [B]',1361040574,'174.000000','088.000000','005.000000','000.000000','467.000000','018.000000','075.500000','0.036750','0.015270','0.225690','0.771717',0,0,0,1,'Axis',5,'Hauptmann');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1200000000000000000000000','Vogel [B]',1361040574,'201.000000','019.000000','102.000000','007.000000','378.000000','000.000000','000.000000','0.000000','0.017618','0.201941','0.765156',0,0,0,1,'Axis',5,'Hauptmann');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1600000000000000000000000','Ludwig [B]',1361040574,'198.000000','053.500000','041.000000','099.000000','354.000000','020.000000','015.000000','0.000000','0.018092','0.190341','0.769515',0,0,0,1,'Axis',5,'Hauptmann');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1500000000000000000000000','Benson [B]',1361040574,'201.000000','334.500000','004.000000','000.000000','387.000000','013.000000','000.000000','0.185257','0.017461','0.000000','0.772146',0,0,0,2,'Allies',6,'Major');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('BCB83A79E0AD66C998BB33B23E38BAB9','Cullen',1360907140,'794.000000','214.500000','000.000000','000.000000','999.999999','155.000000','768.000000','1.385840','0.008325','0.299433','0.777812',0,104,7,2,'Allies',8,'Brigadier General');
/*!40000 ALTER TABLE `player_xp` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- End-Of-File: player_xp.sql

