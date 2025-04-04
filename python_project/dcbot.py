# 導入Discord.py模組
import discord
import random
from random import sample
# 導入commands指令模組
from discord.ext import commands

# intents是要求機器人的權限
intents = discord.Intents.all()
# command_prefix是前綴符號，可以自由選擇($, #, &...)
bot = commands.Bot(command_prefix = "%", intents = intents)

@bot.event
# 當機器人完成啟動
async def on_ready():
    print(f"目前登入身份 --> {bot.user}")

@bot.command()
# 輸入%Hello呼叫指令
async def Hello(ctx):
    # 回覆Hello, world!
    await ctx.send("Hello, world!")

@bot.command()
async def eat(ctx):
    food_options = ["男一", "大一女", "台科大", "活大", "女九", "118", "公館"]
    random_food = random.choice(food_options)
    await ctx.send(random_food)

@bot.command()
async def Raga(ctx):
    await ctx.send("呂睿宏我真的很羨慕你")

bot.run("MTIzOTI2Mjk2Njg1NjAyNDE3NQ.GRCt18.jgNPY29H79uh749Aubb_sBQEPGNfV3gEL1rdTo")