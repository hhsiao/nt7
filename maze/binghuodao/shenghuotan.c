inherit __DIR__"binghuodao";

void create()
{
        set("short", "神火壇");
        set("long",
"這裡是一處寬闊的祭臺，祭臺中間有一根石柱，上面寫著鮮紅\n"
"的三個大字“神火臺”，祭臺四周矗立著四根石柱，上面雕刻著各種\n"
"火焰的模樣。據說在這裡汲取實戰體會（jiqu）能獲得更多收穫。\n"
);
        set("exits", ([ 
                "east"   : __DIR__"guanmulin2", 
                "southwest"   : __DIR__"shenmihuodong2",
        ]));
        setup();
}
