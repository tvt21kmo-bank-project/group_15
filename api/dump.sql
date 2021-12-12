-- MySQL dump 10.13  Distrib 8.0.27, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: bankautomat
-- ------------------------------------------------------
-- Server version	8.0.23

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `asiakas`
--

DROP TABLE IF EXISTS `asiakas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakas` (
  `idAsiakas` int NOT NULL AUTO_INCREMENT,
  `Hetu` varchar(11) NOT NULL,
  `Etunimi` varchar(45) NOT NULL,
  `Sukunimi` varchar(45) NOT NULL,
  `Osoite` varchar(45) NOT NULL,
  `Puhelin` varchar(15) DEFAULT NULL,
  PRIMARY KEY (`idAsiakas`),
  UNIQUE KEY `Hetu_UNIQUE` (`Hetu`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas`
--

LOCK TABLES `asiakas` WRITE;
/*!40000 ALTER TABLE `asiakas` DISABLE KEYS */;
INSERT INTO `asiakas` VALUES (1,'999999-8888','Erkki','Esimerkki','Jokutie 6, 56433 Kaupunki','0446667777'),(2,'111111-2222','Maija','Meikäläinen','Jokutie 6, 56433 Kaupunki','0451112222'),(3,'222222-3333','Matti','Tepponen','Mikätie 6, 56433 Kylä','0406667777');
/*!40000 ALTER TABLE `asiakas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `kortti`
--

DROP TABLE IF EXISTS `kortti`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `kortti` (
  `idKortti` int NOT NULL AUTO_INCREMENT,
  `Kortinnumero` varchar(20) NOT NULL,
  `PIN` varchar(255) NOT NULL,
  `idAsiakas` int NOT NULL,
  `idTili` int NOT NULL,
  PRIMARY KEY (`idKortti`,`idAsiakas`,`idTili`),
  UNIQUE KEY `Kortinnumero_UNIQUE` (`Kortinnumero`),
  KEY `fk_Kortti_Asiakas_idx` (`idAsiakas`),
  KEY `fk_Kortti_Tili1_idx` (`idTili`),
  CONSTRAINT `fk_Kortti_Asiakas` FOREIGN KEY (`idAsiakas`) REFERENCES `asiakas` (`idAsiakas`),
  CONSTRAINT `fk_Kortti_Tili1` FOREIGN KEY (`idTili`) REFERENCES `tili` (`idTili`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `kortti`
--

LOCK TABLES `kortti` WRITE;
/*!40000 ALTER TABLE `kortti` DISABLE KEYS */;
INSERT INTO `kortti` VALUES (1,'98765','$2a$10$lG.6W2/2kmtYj5eMIhlvM.kBqmzTdvrgY97VbX4wRxvj0o/XUdU1u',1,1),(2,'87654','$2a$10$ziPgMB3wNmYaGOn4DnVkyeyUa3EJ4Y199p/.QNIeVwhbQrOys5P12',2,1),(3,'12345','$2a$10$L5L5RcCmyKiSxjVo38EY/.JNHHkzmKqw6Di0qfPJpkZGuvEDsPeQ2',3,3),(4,'76543','$2a$10$fIvAo.eEaeTwim2rK7Y2lehWXMCn0FykHkD4RDc1DaLi3A78g6kBm',2,2);
/*!40000 ALTER TABLE `kortti` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tili`
--

DROP TABLE IF EXISTS `tili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tili` (
  `idTili` int NOT NULL AUTO_INCREMENT,
  `Tilinumero` varchar(18) NOT NULL,
  `Saldo` double NOT NULL,
  `idOmistaja` int NOT NULL,
  PRIMARY KEY (`idTili`),
  UNIQUE KEY `Tilinumero_UNIQUE` (`Tilinumero`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tili`
--

LOCK TABLES `tili` WRITE;
/*!40000 ALTER TABLE `tili` DISABLE KEYS */;
INSERT INTO `tili` VALUES (1,'121212',643042.45,1),(2,'21212121',5000,2),(3,'343434',7420,3);
/*!40000 ALTER TABLE `tili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tilitapahtuma`
--

DROP TABLE IF EXISTS `tilitapahtuma`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tilitapahtuma` (
  `idTapahtuma` int NOT NULL AUTO_INCREMENT,
  `Kortinnumero` varchar(20) DEFAULT NULL,
  `Aika` datetime DEFAULT NULL,
  `Tapahtuma` varchar(10) DEFAULT NULL,
  `Summa` double DEFAULT NULL,
  `idTili` int NOT NULL,
  PRIMARY KEY (`idTapahtuma`),
  KEY `fk_Tilitapahtuma_Tili1_idx` (`idTili`),
  CONSTRAINT `fk_Tilitapahtuma_Tili1` FOREIGN KEY (`idTili`) REFERENCES `tili` (`idTili`)
) ENGINE=InnoDB AUTO_INCREMENT=40 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tilitapahtuma`
--

LOCK TABLES `tilitapahtuma` WRITE;
/*!40000 ALTER TABLE `tilitapahtuma` DISABLE KEYS */;
INSERT INTO `tilitapahtuma` VALUES (1,'12345','2021-12-10 23:18:06','nosto',500,3),(2,'12345','2021-12-10 23:18:31','nosto',10,3),(3,'12345','2021-12-10 23:18:35','nosto',40,3),(4,'12345','2021-12-10 23:18:38','nosto',100,3),(5,'12345','2021-12-10 23:18:40','nosto',500,3),(6,'12345','2021-12-10 23:18:42','nosto',200,3),(7,'12345','2021-12-10 23:19:15','nosto',40,3),(8,'12345','2021-12-10 23:19:25','nosto',30,3),(9,'12345','2021-12-10 23:19:31','nosto',60,3),(10,'12345','2021-12-10 23:19:34','nosto',90,3),(11,'12345','2021-12-10 23:20:37','nosto',20,3),(12,'12345','2021-12-10 23:20:40','nosto',40,3),(13,'12345','2021-12-10 23:20:42','nosto',60,3),(14,'12345','2021-12-10 23:20:44','nosto',100,3),(15,'12345','2021-12-10 23:20:46','nosto',200,3),(16,'12345','2021-12-10 23:20:48','nosto',500,3),(17,'12345','2021-12-10 23:20:53','nosto',80,3),(18,'12345','2021-12-10 23:20:57','nosto',10,3),(19,'87654','2021-12-10 23:22:00','nosto',100,1),(20,'87654','2021-12-10 23:22:02','nosto',40,1),(21,'87654','2021-12-10 23:22:06','nosto',20,1),(22,'87654','2021-12-10 23:22:08','nosto',40,1),(23,'87654','2021-12-10 23:22:10','nosto',60,1),(24,'87654','2021-12-10 23:22:13','nosto',100,1),(25,'87654','2021-12-10 23:22:15','nosto',200,1),(26,'87654','2021-12-10 23:22:16','nosto',500,1),(27,'87654','2021-12-10 23:22:29','nosto',870,1),(28,'87654','2021-12-10 23:23:13','nosto',40,1),(29,'87654','2021-12-10 23:23:16','nosto',200,1),(30,'98765','2021-12-10 23:23:49','nosto',20,1),(31,'98765','2021-12-10 23:23:52','nosto',40,1),(32,'98765','2021-12-10 23:23:53','nosto',60,1),(33,'98765','2021-12-10 23:23:56','nosto',100,1),(34,'98765','2021-12-10 23:23:58','nosto',200,1),(35,'98765','2021-12-10 23:24:00','nosto',500,1),(36,'98765','2021-12-10 23:24:09','nosto',10,1),(37,'87654','2021-12-10 23:34:59','nosto',40,1),(38,'87654','2021-12-10 23:35:02','nosto',100,1),(39,'87654','2021-12-10 23:35:33','nosto',50,1);
/*!40000 ALTER TABLE `tilitapahtuma` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'bankautomat'
--
/*!50003 DROP PROCEDURE IF EXISTS `debit_nosto` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `debit_nosto`(
IN maara DOUBLE,
IN kortti VARCHAR(20),
IN tili VARCHAR(18))
BEGIN
DECLARE testi INT DEFAULT 0;
DECLARE tili_id INT DEFAULT 0;
SELECT idTili INTO tili_id FROM Tili WHERE tilinumero=tili;
START TRANSACTION;
UPDATE Tili SET saldo=saldo-maara WHERE tilinumero=tili AND saldo>=maara;
SET testi=ROW_COUNT();
IF (testi > 0) THEN
	COMMIT;
    INSERT INTO Tilitapahtuma(Kortinnumero,Aika,Tapahtuma,Summa,idTili) VALUES(kortti,NOW(),'nosto',maara,tili_id);
ELSE
	ROLLBACK;
END IF;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `selaa_tapahtumia` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `selaa_tapahtumia`(
IN edel_viim INT,
IN tili VARCHAR(18))
BEGIN
DECLARE tili_id INT DEFAULT 0;
SELECT idTili INTO tili_id FROM Tili WHERE tilinumero=tili;
SELECT kortinnumero, aika, tapahtuma, summa FROM Tilitapahtuma WHERE idTili=tili_id 
	ORDER BY idTapahtuma DESC LIMIT edel_viim, 10;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-12-12 11:07:25
