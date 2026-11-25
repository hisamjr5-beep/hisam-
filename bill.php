
<?php
$bill = 0;
if (isset($_POST['calculate'])) {
    $name = htmlspecialchars($_POST['name']);
    $consumer = htmlspecialchars($_POST['consumer']);
    $previous = (int)$_POST['previous'];
    $current = (int)$_POST['current'];
    $tariff = $_POST['tariff'];
    $units = $current - $previous;

    if ($units < 0) {
        $error = "Invalid meter reading";
    } else {
        if ($tariff == "Domestic") {
            if ($units <= 50) $bill = $units * 3.25;
            elseif ($units <= 100) $bill = 162.5 + ($units-50)*4.05;
            elseif ($units <= 150) $bill = 365 + ($units-100)*5.10;
            else $bill = 620 + ($units-150)*6.50;
        } else {
            $bill = $units * 7.50;
        }
        $energy = $bill;
        $fixed = 10;
        $bill += $fixed;
    }
}
?>
<style>

body {
    font-family: Arial, sans-serif;
    background: #edf1f5;
    padding: 20px;
}

.container {
    max-width: 650px;
    margin: auto;
    background: white;
    padding: 25px;
    border: 1px solid #ccc;
}

.header {
    text-align: center;
    border-bottom: 3px solid #087c43;
    padding-bottom: 12px;
}

.header h2 {
    color: #087c43;
    margin: 5px;
}

.header p {
    margin: 4px;
    font-size: 13px;
}

h3 {
    background: #e7f3ec;
    padding: 9px;
    color: #087c43;
}

input, select {
    padding: 9px;
    width: 95%;
    margin: 7px 0;
    border: 1px solid #aaa;
}

button {
    background: #087c43;
    color: white;
    padding: 11px 25px;
    border: none;
    cursor: pointer;
}

button:hover {
    background: #065c32;
}

table {
    width: 100%;
    border-collapse: collapse;
    margin-top: 15px;
}

td, th {
    border: 1px solid #bbb;
    padding: 10px;
    text-align: left;
}

.total {
    background: #e7f3ec;
    font-size: 19px;
    font-weight: bold;
}

.footer {
    text-align: center;
    margin-top: 20px;
    font-size: 12px;
    color: #555;
}

@media print {
    body {
        background: white;
        padding: 0;
    }

    .container {
        border: none;
    }

    button {
        display: none;
    }
}

</style>

<div class="container">
<div class="header">
<h2>KERALA STATE ELECTRICITY BOARD</h2>
<p>LIMITED - ELECTRICITY BILL</p>
<p>Consumer Billing Statement</p>
</div>

<?php if (!isset($_POST['calculate']) || isset($error)) { ?>
<h3>Consumer Details</h3>
<form method="post">
<input name="name" placeholder="Consumer Name" required>
<input name="consumer" placeholder="Consumer Number" required>
<input type="number" name="previous" placeholder="Previous Reading" min="0" required>
<input type="number" name="current" placeholder="Present Reading" min="0" required>
<select name="tariff">
<option>Domestic</option>
<option>Commercial</option>
</select>
<button name="calculate">Generate Bill</button>
</form>
<?php } ?>

<?php
if (isset($error)) echo "<p style='color:red'>$error</p>";
if (isset($_POST['calculate']) && !isset($error)) {
?>
<h3>Consumer Information</h3>
<table>
<tr><td>Consumer Name</td><td><?php echo $name ?></td></tr>
<tr><td>Consumer Number</td><td><?php echo $consumer ?></td></tr>
<tr><td>Tariff Category</td><td><?php echo $tariff ?></td></tr>
</table>

<h3>Meter Reading Details</h3>
<table>
<tr><td>Previous Reading</td><td><?php echo $previous ?></td></tr>
<tr><td>Present Reading</td><td><?php echo $current ?></td></tr>
<tr><td>Units Consumed</td><td><?php echo $units ?> Units</td></tr>
</table>

<h3>Bill Calculation</h3>
<table>
<tr><td>Energy Charges</td><td>Rs. <?php echo number_format($energy,2) ?></td></tr>
<tr><td>Fixed Charges</td><td>Rs. <?php echo number_format($fixed,2) ?></td></tr>
<tr class="total"><td>Total Amount</td>
<td>Rs. <?php echo number_format($bill,2) ?></td></tr>
</table>

<div class="footer">
<p>Please pay your electricity bill on time.</p>
<p>Thank you! | Kerala State Electricity Board</p>
<button onclick="window.print()">Print Bill</button>
</div>
<?php } ?>
</div>

