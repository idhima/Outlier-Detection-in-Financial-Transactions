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
