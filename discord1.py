import os
from dhooks import Webhook, Embed


WEBHOOK_URL = [os.getenv('WEBHOOK_MAIN1')]
for url in WEBHOOK_URL:
    hook = Webhook(url)

    embed = Embed(
        description="**[OOP glavna stranica je azurirana - click here -](https://cs.elfak.ni.ac.rs/nastava/course/view.php?id=45)**",
        color=0x3498DB
    )

    hook.send("@everyone 📢 OOP", embed=embed)
