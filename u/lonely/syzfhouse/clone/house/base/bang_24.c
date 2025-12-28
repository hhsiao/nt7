
inherit "/inherit/room/house_base";

void create()
{
    set("short", "青石坪");
    set("long", @LONG
這裡是上山路側的一處平臺，由平坦的大小青石拼湊而成。石間
挺立三四株翠柏，樹下偶爾會有歇腳的進香客人。一條清澈見底的小
溪從坪前繞過，靜靜橫在坪後的宏大莊院門前，看來似是江湖中某個
幫會的駐地所在。
LONG);

    set("exits",
    ([
        "north"  : "/d/emei/qing-shijie1",
    ]));

    set("outdoors", "emei");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
