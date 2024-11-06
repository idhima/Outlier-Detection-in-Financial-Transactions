document.addEventListener("DOMContentLoaded", () => {
    const form = document.getElementById("uploadForm");
    const resultSection = document.getElementById("result");
    const fileInput = document.querySelector('input[name="transactionFile"]');

    form.addEventListener("submit", async (event) => {
        event.preventDefault();
        
        // Basic client-side file type validation
        if (!fileInput.files.length || !fileInput.files[0].name.endsWith(".txt")) {
            alert("Please upload a valid .txt file.");
            return;
        }

        const formData = new FormData(form);
        try {
            const response = await fetch("/cgi-bin/main.cgi", {
                method: "POST",
                body: formData
            });

            if (response.ok) {
                const resultHTML = await response.text();
                resultSection.innerHTML = resultHTML;
            } else {
                resultSection.innerHTML = "<p class='error'>Error processing the request. Please try again.</p>";
            }
        } catch (error) {
            console.error("Error:", error);
            resultSection.innerHTML = "<p class='error'>An unexpected error occurred. Please try again later.</p>";
        }
    });
});
//to display data
function displayChart(transactions, outliers) {
    const ctx = document.getElementById('transactionChart').getContext('2d');
    const data = {
        labels: transactions.map((_, index) => `T${index}`),
        datasets: [
            {
                label: 'Transactions',
                data: transactions,
                borderColor: 'rgba(75, 192, 192, 1)',
                backgroundColor: outliers.map(isOutlier => isOutlier ? 'rgba(255, 99, 132, 0.2)' : 'rgba(75, 192, 192, 0.2)'),
                borderWidth: 1
            }
        ]
    };
    new Chart(ctx, {
        type: 'bar',
        data: data,
        options: {
            responsive: true,
            scales: {
                y: {
                    beginAtZero: true
                }
            }
        }
    });
}
