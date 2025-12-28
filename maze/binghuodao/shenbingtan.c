inherit __DIR__"binghuodao";

void create()
{
        set("short", "神冰壇");
        set("long",
"這裡是一處寬闊的祭臺，祭臺中間有一根石柱，上面寫著藍色\n"
"的三個大字“神冰臺”，祭臺四周矗立著四根石柱，上面雕刻著各種\n"
"冰獸的模樣。據說在這裡研究技能（yanjiu）能獲得更多收穫。\n"
);
        set("exits", ([ 
                "east"   : __DIR__"guanmulin1", 
                "northwest"   : __DIR__"shenmibingdong2",
        ]));
        setup();
}
