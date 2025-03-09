<?php
require_once("../shared/head.php");
?>
<body>
    <div id="wrap">
        <?php
        require_once("../shared/header.php");
        ?>
        <div id="content-wrap">
            <?php
            require_once("../shared/sidebar.php");
            ?>
            <div id="main">
                <h1>About InterQL</h1>
                <p><strong>InterQL</strong> is an query language designed to simplify the retrieval of web information, such as metadata, DNS records, SSL data, and IP addresses. It is built with a user-friendly SQL-like syntax that makes it easy for developers to access and manipulate web data efficiently.</p>

                <h2>Features</h2>
                <ul>
                    <li>SQL-like syntax for intuitive querying</li>
                    <li>Support for metadata retrieval from websites</li>
                    <li>Access to DNS records and SSL data</li>
                    <li>Filtering capabilities with <code>WHERE</code> and <code>LIMIT</code></li>
                    <li>Flexible parsing engine API for seamless integration</li>
                </ul>

                <h2>Getting Started</h2>
                <p>To get started with InterQL, you can visit Github at <a href="https://github.com/InterQL">github.com/InterQL</a> where you can experiment with various queries.</p>

                <h2>Code Example</h2>
                <p>Here’s a simple example of how to use InterQL to query metadata:</p>
                <pre><code>request dns.txt from example.com where dns.txt contains "v=spf1";</code></pre>

                <h2>Contact</h2>
                <p>If you have any questions or feedback, feel free to reach out via our website or contribute on GitHub.</p>

                <p class="post-footer align-right">
                    <span class="date">Updated on: March 9, 2025</span>
                </p>
            </div>
        </div>
        <?php
            require_once("../shared/footer.php");
        ?>
    </div>
</body>

</html>
