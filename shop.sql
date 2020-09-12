-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Sep 09, 2020 at 05:04 PM
-- Server version: 10.4.13-MariaDB
-- PHP Version: 7.4.8

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `shop`
--

-- --------------------------------------------------------

--
-- Table structure for table `Customer_list`
--

CREATE TABLE `Customer_list` (
  `Customer_id` int(6) NOT NULL,
  `First_name` varchar(30) NOT NULL,
  `Middle_name` varchar(30) NOT NULL,
  `Last_name` varchar(30) NOT NULL,
  `Contact-number` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `customer_order`
--

CREATE TABLE `customer_order` (
  `order_id` int(6) NOT NULL,
  `Customer_id` int(6) NOT NULL,
  `Item_id` int(6) NOT NULL,
  `Quantity` double NOT NULL,
  `Unit` varchar(20) NOT NULL,
  `item_total_price` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `Item`
--

CREATE TABLE `Item` (
  `Item_id` int(6) NOT NULL,
  `Item_name` varchar(60) NOT NULL,
  `Quantity` decimal(10,0) NOT NULL,
  `Unit` varchar(20) NOT NULL,
  `Category` varchar(50) NOT NULL,
  `Item_price` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `Item`
--

INSERT INTO `Item` (`Item_id`, `Item_name`, `Quantity`, `Unit`, `Category`, `Item_price`) VALUES
(1, 'Dress', '2000', 'NULL', 'Others', 200),
(2, 'hand watch', '100', 'NULL', 'Technology', 800),
(3, 'Smart Phone', '80', 'NULL', 'Technology', 6000),
(4, 'TV', '150', 'NULL', 'Entertainment', 10000),
(5, 'Washing Machine', '50', 'NULL', 'Technology', 20000),
(6, 'Text Book', '200', 'NULL', 'education', 60),
(7, 'Copies', '600', 'NULL', 'education', 20),
(8, 'pen & pencil', '200', 'NULL', 'education', 10),
(9, 'potatoes', '100', 'kg', 'food', 30),
(10, 'Mustard Oil', '200', 'liters', 'food', 124),
(11, 'Turmeric Powder', '20', 'kg', 'food', 80),
(12, 'Rice', '1000', 'kg', 'food', 1100),
(13, 'spices', '200', 'kg', 'food', 80);

-- --------------------------------------------------------

--
-- Table structure for table `vendor`
--

CREATE TABLE `vendor` (
  `Vendor_id` int(6) NOT NULL,
  `Vendor_name` varchar(50) NOT NULL,
  `Vendor_username` text NOT NULL,
  `Vendor_email` varchar(200) NOT NULL,
  `Vendor_password` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `vendor`
--

INSERT INTO `vendor` (`Vendor_id`, `Vendor_name`, `Vendor_username`, `Vendor_email`, `Vendor_password`) VALUES
(1, 'Ratan Roy', 'ratan@345', 'ratan.roy@gmail.com', 'Ratan@1256'),
(2, 'Shima Pal', 'Shima@21', 'Shima@ialoy.com', 'Shima@5694'),
(3, 'Sneha Singh', 'Sneha', 'snehasingh07@gmail.com', 'Sneha@2376'),
(4, 'Dimple Roy', 'Dimple_41', 'dimple453@gmail.com', 'Dimple@4805'),
(5, 'Tarun Ghosh', 'Tarun@ghosh', 'tarun896@ialoy.com', 'Tarun@5638');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `Customer_list`
--
ALTER TABLE `Customer_list`
  ADD PRIMARY KEY (`Customer_id`);

--
-- Indexes for table `customer_order`
--
ALTER TABLE `customer_order`
  ADD PRIMARY KEY (`order_id`),
  ADD KEY `order_customer_fk` (`Customer_id`),
  ADD KEY `item_customer_fk` (`Item_id`);

--
-- Indexes for table `Item`
--
ALTER TABLE `Item`
  ADD PRIMARY KEY (`Item_id`);

--
-- Indexes for table `vendor`
--
ALTER TABLE `vendor`
  ADD PRIMARY KEY (`Vendor_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `Customer_list`
--
ALTER TABLE `Customer_list`
  MODIFY `Customer_id` int(6) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `Item`
--
ALTER TABLE `Item`
  MODIFY `Item_id` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- AUTO_INCREMENT for table `vendor`
--
ALTER TABLE `vendor`
  MODIFY `Vendor_id` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `customer_order`
--
ALTER TABLE `customer_order`
  ADD CONSTRAINT `item_customer_fk` FOREIGN KEY (`Item_id`) REFERENCES `Item` (`Item_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `order_customer_fk` FOREIGN KEY (`Customer_id`) REFERENCES `Customer_list` (`Customer_id`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
