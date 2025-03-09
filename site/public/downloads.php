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
                <h1>Download InterQL</h1>
                <p><strong>InterQL</strong> is currently in the early stages of development, so direct download options are not yet available. However, you can easily clone the Git repository and build the project locally.</p>

                <h2>Clone the Repository</h2>
                <p>To get started, use the following command to clone the InterQL repository:</p>
                <pre><code>git clone https://github.com/interql/interql.git</code></pre>

                <h2>Build the Project</h2>
                <p>After cloning the repository, navigate to the project directory:</p>
                <pre><code>cd interql</code></pre>
                <p>Next, run the following command to build the project:</p>
                <pre><code>make</code></pre>
                <p>This will compile the necessary components and prepare InterQL for use. Ensure you have <code>make</code> installed on your system.</p>

                <h2>Using InterQL</h2>
                <p>Before compiling, modify the <code>main.c</code> file to set your desired query. For example:</p>
                <pre><code>const char *input = "verify ssl.cert.issuer contains \"Let's Encrypt\" in example.com;";</code></pre>
                <p>A list of possible example queries can be found <a href="https://github.com/InterQL/InterQL/blob/main/queries.txt">here</a>.</p>

                <h2>InterQL SC Download</h2>
                <p><a href="https://github.com/InterQL/InterQL/archive/refs/heads/main.zip">Download</a></p>

                <h2>Feedback and Contributions</h2>
                <p>We welcome feedback and contributions! If you have any questions or suggestions, feel free to open an issue on GitHub or reach out through our contact page.</p>
            </div>
        </div>
        <?php
        require_once("../shared/footer.php");
        ?>
    </div>
</body>

</html>
