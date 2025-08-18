import os
from dhooks import Webhook, Embed, File

image2_path = 'cs-oop1-nova-obavestenja.png'

WEBHOOK_URL = [os.getenv('WEBHOOK_MAIN1')]
for url in WEBHOOK_URL:
    hook = Webhook(url)

    embed = Embed(
        description="**[OOP main page link - click here -](https://cs.elfak.ni.ac.rs/nastava/course/view.php?id=45)**",
        color=0x3498DB
    )

    embed.set_image(url="attachment://cs-oop1-nova-obavestenja.png")
    file = File(image2_path, name="cs-oop1-nova-obavestenja.png")
    hook.send("@everyone 📢 OOP", embed=embed, file=file)
