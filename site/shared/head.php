<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="description" content="<?php echo isset($description) ? htmlspecialchars($description) : 'InterQL - An SQL-like query language server designed for retrieving information about content on the internet. It provides a structured interface for querying and extracting data from online sources, leveraging a custom parsing engine to process user-defined requests.'; ?>">
    <meta name="author" content="Emanuel Rukavina <emanuel.rukavina.dev@pm.me>">
    <meta name="robots" content="index, follow">
    
    <!-- Open Graph / Social Media Meta Tags -->
    <meta property="og:title" content="<?php echo isset($title) ? htmlspecialchars($title) : 'InterQL'; ?>">
    <meta property="og:type" content="website">
    <meta property="og:url" content="<?php echo 'https://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']; ?>">
    <meta property="og:description" content="<?php echo isset($description) ? htmlspecialchars($description) : 'InterQL - An SQL-like query language server designed for retrieving information about content on the internet. It provides a structured interface for querying and extracting data from online sources, leveraging a custom parsing engine to process user-defined requests.'; ?>">
    
    <!-- CSS -->
    <link rel="stylesheet" href="images/Envision.css" type="text/css">
    
    <!-- Title -->
    <title><?php echo isset($title) ? htmlspecialchars($title) : 'InterQL'; ?></title>
    
</head>