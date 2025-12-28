// /clone/board/lonely_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("溫馨筆記", ({ "board" }) );
        set("location", "/data/room/dcgz/woshi");
        set("board_id", "dcgz_b");
        set("long", "這是一個專供Juice使用的留言板。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

