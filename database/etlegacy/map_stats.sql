-- -------------------------------------------------------------------
-- ET Database
-- -------------------------------------------------------------------

-- Table      : map_stats
-- Filename   : etlegacy/map_stats.sql
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
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('ge_temple_v2a','0.000000','0.925588',17,'Malone');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('goldrush','0.062183','0.973440',22,'Malone');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('radar','0.026536','0.988821',8,'Weissmann [B]');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('crevasse_pe','0.000000','1.000000',0,'');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('navarone','0.098252','0.961830',17,'Cullen');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('trmfght_beta2','0.000000','1.000000',0,'');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('oasis','1.095913','0.686551',17,'Malone');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('et_mor_pro','0.664833','0.866067',26,'Malone');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('citadel_obj','0.130456','0.950948',14,'Cullen');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('battery','0.033226','0.986085',7,'Bauer [B]');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('et_beach','0.186538','0.935678',10,'Fischer [B]');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('braundorf_final','0.093145','0.961902',10,'Malone');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('venice','0.076385','0.968130',16,'Cullen');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('lighthouse','0.019947','0.991067',18,'Cullen');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('coast_b1','0.018654','0.991558',5,'Maloney [B]');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('caen_4','0.000000','0.975899',14,'Cullen');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('pha_chateau','0.016110','0.992594',5,'Fischer [B]');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('bremen_final','0.259492','0.925584',11,'Cullen');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('destruction_final','0.011974','0.994719',4,'Krause [B]');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('exodus_a4b','0.000000','0.977334',29,'Malone');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('rochelle_b2','0.012261','0.994199',7,'Cullen');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('base12_b6','0.000000','0.994326',14,'Washington [B]');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('bergen','0.080300','0.969242',8,'Himmel [B]');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('flame-guards','0.000000','1.000000',0,'');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('fortress','0.059038','0.975155',14,'Cullen');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('mp_sub_rc1','0.045973','0.979903',5,'Cullen');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('snatch3','0.000000','1.000000',0,'');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('supplydepot2','0.039482','0.981938',9,'Vogel [B]');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('tc_base','0.000000','1.000000',0,'');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('townsquare_final','0.067572','0.971237',4,'Meiner [B]');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('v2base','0.057710','0.975613',6,'Zimmermann [B]');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('v2_factory','0.000000','1.000000',0,'');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('mcassino','0.040518','0.982258',6,'Keller [B]');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('railgun','0.000000','1.000000',0,'');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('axislab_final','0.000000','1.000000',0,'');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('fueldump','0.000000','1.000000',0,'');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('adlernest','0.000000','1.000000',0,'');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('eagles2_a6','0.037112','0.983405',67,'Ludwig [B]');
INSERT INTO `map_stats` (`map_name`, `rating`, `rating_variance`, `spree_record`, `spree_name`) VALUES ('am_hydro_dam','0.000000','1.000000',0,'');
/*!40000 ALTER TABLE `map_stats` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- End-Of-File: map_stats.sql

