inherit ROOM;
void create()
{
        set("short", "清心閣");
        set("long",@LONG
這是寺中諸僧參修清心淨欲的地方。閣中只有地面放有幾個蒲團，
角落裡擺了一張桌子，上面並排立著五支點燃的蠟燭(candle)。除此之
外別無它物，確然是個清靜之處。
LONG);
        set("exits", ([
		"east": __DIR__"shiyuan",
        ]));
        set("item_desc",([
                "candle" : "五支點燃了的長蠟燭，跳躍的火焰似乎溫暖了整個房間。\n",
        ]) );
        set("no_fight",1);
        set("coor/x",-400);
  set("coor/y",-310);
   set("coor/z",30);
   setup();
}
void init()
{
        add_action("do_shoot", ({"shoot", "she"}));
}

int do_shoot(string arg)
{
        object me = this_player();
        int level, jinglicost;

        level = me->query_skill("finger", 1);
        if (arg == "candle" || arg == "zhu" || arg == "lazhu") {
                jinglicost = level / 3 + random(level / 3);
                if (me->query("jingli") <= jinglicost) {
                        write("你太累了，先歇歇吧！\n");
                        return 1;
                }
                if (level < 30) {
                        write("你將手指對準蠟燭，試圖運氣於指對蠟燭射去，卻怎麼也擠不出指風來。\n");
                        return 1;
                }
                me->receive_damage("jingli", jinglicost);
                if (level <= 100) {
                        write("你運氣於指，一縷指風對準蠟燭射去，");
                        if (level < 40) write("蠟燭的火苗微微晃了一晃。\n");
                        else if (level < 50) write("蠟燭的火苗晃了一晃。\n");
                        else if (level < 60) write("蠟燭的火苗晃了幾晃。\n");
                        else if (level < 70) write("蠟燭的火苗狠狠地晃了幾晃才穩下來。\n");
                        else if (level < 80) write("蠟燭的火苗被射得東倒西歪，停了一下又跳躍起來。\n");
                        else if (level < 90) write("蠟燭的火苗被射得東倒西歪，過了半天才又跳躍起來。\n");
                        else write("“嗤”地一聲輕響，蠟燭的火苗幾乎滅了，掙紮了幾下才又重新跳躍起來。\n");
                        me->improve_skill("finger", me->query("int"));
                        if (!random(5)) message("vision", "$N對著蠟燭指指點點，不知在做什麼。\n", me, ({ me }));
                }
                else {
                        write("“噗”地一聲，蠟燭被你的指風射滅了！\n");
                        write("黑暗中有人大叫：“哪個混蛋乾的？！”，你趕忙跑過去把蠟燭重新點燃。\n");
                }
                return 1;
        }
        return notify_fail("你要謀殺誰？\n");
}
