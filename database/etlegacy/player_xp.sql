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
  `guid` varchar(32) NOT NULL COMMENT 'Client GUID',
  `name` varchar(40) NOT NULL COMMENT 'Player Name',
  `time` bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'L:ast Seen',
  `skill0` decimal(9,6) unsigned zerofill NOT NULL DEFAULT '000.000000' COMMENT 'Battle Sense',
  `skill1` decimal(9,6) unsigned zerofill NOT NULL DEFAULT '000.000000' COMMENT 'Engineering',
  `skill2` decimal(9,6) unsigned zerofill NOT NULL DEFAULT '000.000000' COMMENT 'First Aid',
  `skill3` decimal(9,6) unsigned zerofill NOT NULL DEFAULT '000.000000' COMMENT 'Signals',
  `skill4` decimal(9,6) unsigned zerofill NOT NULL DEFAULT '000.000000' COMMENT 'Light Weapons',
  `skill5` decimal(9,6) unsigned zerofill NOT NULL DEFAULT '000.000000' COMMENT 'Heavy Weapons',
  `skill6` decimal(9,6) unsigned zerofill NOT NULL DEFAULT '000.000000' COMMENT 'Covert Ops',
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
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0100000000000000000000000','Bauer [B]',1361108542,'337.000000','309.500000','155.000000','000.000000','576.000000','020.000000','033.500000','0.201917','0.010584','0.000000','0.693680',0,20,6,1,'Axis',7,'Oberst');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0200000000000000000000000','Smith [B]',1361108542,'292.000000','260.000000','081.000000','002.000000','590.000000','000.000000','027.500000','0.000000','0.010937','0.309173','0.680180',0,11,2,2,'Allies',6,'Major');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0300000000000000000000000','Vogel [B]',1361108542,'313.000000','094.500000','089.000000','028.000000','612.000000','024.000000','046.500000','0.061605','0.011318','0.000000','0.687020',0,13,3,1,'Axis',5,'Hauptmann');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0400000000000000000000000','Johnson [B]',1361108542,'288.000000','109.500000','150.000000','011.000000','567.000000','036.000000','007.500000','0.000000','0.011219','0.264603','0.680655',0,26,0,2,'Allies',6,'Major');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0500000000000000000000000','Lange [B]',1361108542,'334.000000','132.000000','100.000000','088.000000','639.000000','034.000000','040.000000','0.240002','0.011268','0.000000','0.697809',0,37,3,1,'Axis',5,'Hauptmann');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0600000000000000000000000','Whittman [B]',1361108542,'324.000000','049.500000','100.000000','061.000000','639.000000','012.000000','009.000000','0.000000','0.011319','0.281423','0.672770',0,17,0,2,'Allies',5,'Captain');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0700000000000000000000000','Heinrich [B]',1361108542,'319.000000','087.500000','055.000000','022.000000','662.000000','022.000000','049.000000','0.083848','0.011084','0.000000','0.707382',0,42,0,1,'Axis',5,'Hauptmann');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0800000000000000000000000','Meiner [B]',1361108542,'310.000000','312.000000','024.000000','001.000000','632.000000','001.000000','008.500000','0.000000','0.011016','0.131231','0.683940',0,17,3,1,'Axis',6,'Major');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0900000000000000000000000','Miller [B]',1361108542,'386.000000','125.500000','025.000000','006.000000','616.000000','019.000000','136.000000','0.121568','0.012302','0.000000','0.692764',0,46,6,2,'Allies',5,'Captain');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1000000000000000000000000','Lorenz [B]',1361108542,'335.000000','150.500000','080.000000','025.000000','554.000000','006.000000','047.500000','0.000000','0.011783','0.507385','0.680941',0,30,0,1,'Axis',6,'Major');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1100000000000000000000000','Barton [B]',1361108542,'241.000000','183.000000','077.000000','037.000000','540.000000','013.000000','040.000000','0.000000','0.011069','0.000000','0.696133',0,19,0,2,'Allies',6,'Major');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1800000000000000000000000','Barton [B]',1361046059,'006.000000','000.000000','009.000000','000.000000','023.000000','000.000000','000.000000','0.000000','0.196582','0.084927','0.982909',0,0,0,2,'Allies',1,'Private 1st Class');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('ECEBD89CADE1E45BBD5F626091963F7E','Malone',1361108542,'999.999999','531.000000','000.000000','000.000000','999.999999','251.000000','999.999999','1.542471','0.006131','0.825737','0.569327',0,79,0,2,'Allies',8,'Brigadier General');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1300000000000000000000000','Callahan [B]',1361108542,'330.000000','043.000000','085.000000','171.000000','580.000000','012.000000','020.500000','0.000000','0.010519','0.208422','0.706989',0,65,6,2,'Allies',6,'Major');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1700000000000000000000000','Kowalski [B]',1361046060,'221.000000','084.500000','136.000000','022.000000','397.000000','002.000000','023.000000','0.000000','0.016396','0.000000','0.730348',0,0,0,2,'Allies',5,'Captain');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1400000000000000000000000','Kruger [B]',1361108542,'274.000000','224.000000','005.000000','004.000000','661.000000','018.000000','075.500000','0.084917','0.010122','0.000000','0.704129',0,34,3,1,'Axis',6,'Major');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1200000000000000000000000','Jung [B]',1361108542,'309.000000','019.000000','121.000000','048.000000','581.000000','000.000000','007.500000','0.000000','0.011179','0.000000','0.696738',0,21,3,1,'Axis',5,'Hauptmann');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1600000000000000000000000','Washington [B]',1361107870,'236.000000','053.500000','055.000000','104.000000','406.000000','020.000000','015.000000','0.000000','0.015572','0.152852','0.739323',0,0,0,2,'Allies',5,'Captain');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1500000000000000000000000','Kowalski [B]',1361108542,'276.000000','443.500000','004.000000','000.000000','607.000000','013.000000','000.000000','0.145628','0.011265','0.212530','0.708810',0,53,1,2,'Allies',6,'Major');
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

