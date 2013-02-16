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
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0100000000000000000000000','Bauer [B]',1361024542,'206.000000','143.500000','144.000000','000.000000','287.000000','016.000000','033.500000','0.084021','0.019933','0.000000','0.788099',0,42,5,1,'Axis',7,'Oberst');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0200000000000000000000000','Smith [B]',1361024542,'200.000000','078.500000','074.000000','002.000000','361.000000','000.000000','027.500000','0.000000','0.017783','0.244085','0.786083',0,34,0,2,'Allies',5,'Captain');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0300000000000000000000000','Vogel [B]',1361024542,'201.000000','061.500000','030.000000','001.000000','423.000000','016.000000','041.500000','0.165294','0.018591','0.000000','0.783562',0,28,2,1,'Axis',5,'Hauptmann');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0400000000000000000000000','Rowan [B]',1361024542,'155.000000','106.500000','030.000000','005.000000','337.000000','036.000000','007.500000','0.000000','0.018724','0.211637','0.790275',0,57,0,2,'Allies',5,'Captain');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0500000000000000000000000','Weissmann [B]',1361024542,'200.000000','045.500000','025.000000','047.000000','341.000000','030.000000','040.000000','0.162289','0.020534','0.000000','0.796643',0,60,2,1,'Axis',5,'Hauptmann');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0600000000000000000000000','Kowalski [B]',1361024542,'192.000000','032.000000','031.000000','037.000000','340.000000','012.000000','009.000000','0.000000','0.019377','0.201635','0.780966',0,55,2,2,'Allies',5,'Captain');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0700000000000000000000000','Bohm [B]',1361024542,'202.000000','068.000000','026.000000','012.000000','409.000000','017.000000','039.000000','0.144160','0.018093','0.000000','0.797702',0,58,3,1,'Axis',5,'Hauptmann');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0800000000000000000000000','Miller [B]',1361024542,'206.000000','233.500000','024.000000','001.000000','355.000000','000.000000','000.000000','0.000000','0.019283','0.259469','0.782373',0,55,0,2,'Allies',6,'Major');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT0900000000000000000000000','Fischer [B]',1361024542,'228.000000','118.500000','003.000000','006.000000','361.000000','019.000000','037.000000','0.242832','0.021290','0.000000','0.792732',0,60,3,1,'Axis',5,'Hauptmann');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1000000000000000000000000','Barton [B]',1361024542,'224.000000','098.000000','030.000000','002.000000','341.000000','006.000000','035.000000','0.000000','0.019206','0.243031','0.782678',0,40,1,2,'Allies',5,'Captain');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1100000000000000000000000','Lorenz [B]',1361024542,'163.000000','170.000000','064.000000','031.000000','391.000000','005.000000','000.000000','0.248486','0.016941','0.000000','0.796474',0,84,2,1,'Axis',6,'Major');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1800000000000000000000000','Jones [B]',1361024156,'004.000000','000.000000','000.000000','000.000000','015.000000','000.000000','000.000000','0.394941','0.343874','0.032960','0.997631',0,17,2,2,'Allies',0,'Private');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('ECEBD89CADE1E45BBD5F626091963F7E','Malone',1361024670,'999.999999','503.500000','000.000000','000.000000','999.999999','251.000000','926.000000','1.473044','0.007519','0.827165','0.630526',0,0,0,2,'Allies',8,'Brigadier General');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1300000000000000000000000','Jung [B]',1361024542,'191.000000','010.500000','000.000000','170.000000','375.000000','012.000000','017.500000','0.000000','0.016314','0.000000','0.791676',0,108,37,1,'Axis',6,'Major');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1700000000000000000000000','Lange [B]',1361024542,'170.000000','084.500000','126.000000','001.000000','321.000000','002.000000','023.000000','0.000000','0.021498','0.000000','0.791712',0,35,0,1,'Axis',5,'Hauptmann');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1400000000000000000000000','Shaw [B]',1361024542,'168.000000','053.000000','005.000000','000.000000','428.000000','018.000000','068.000000','0.019471','0.016931','0.257719','0.796582',0,50,3,2,'Allies',5,'Captain');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1200000000000000000000000','Washington [B]',1361024542,'187.000000','019.000000','102.000000','007.000000','362.000000','000.000000','000.000000','0.000000','0.018593','0.235935','0.786078',0,39,0,2,'Allies',5,'Captain');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1600000000000000000000000','Morgan [B]',1361024542,'178.000000','053.500000','041.000000','099.000000','336.000000','012.000000','015.000000','0.000000','0.019542','0.208865','0.789679',0,40,2,2,'Allies',5,'Captain');
INSERT INTO `player_xp` (`guid`, `name`, `time`, `skill0`, `skill1`, `skill2`, `skill3`, `skill4`, `skill5`, `skill6`, `kill_rating`, `kill_variance`, `rating`, `rating_variance`, `mutetime`, `hits`, `team_hits`, `team`, `teamName`, `rank`, `rankName`) VALUES ('OMNIBOT1500000000000000000000000','Himmel [B]',1361024542,'191.000000','274.500000','004.000000','000.000000','362.000000','010.000000','000.000000','0.161822','0.019354','0.000000','0.800901',0,40,7,1,'Axis',6,'Major');
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

