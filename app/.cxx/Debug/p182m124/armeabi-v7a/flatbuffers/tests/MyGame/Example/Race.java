// automatically generated by the FlatBuffers compiler, do not modify

package MyGame.Example;

@SuppressWarnings("unused")
public final class Race {
  private Race() { }
  public static final byte None = -1;
  public static final byte Human = 0;
  public static final byte Dwarf = 1;
  public static final byte Elf = 2;

  public static final String[] names = { "None", "Human", "Dwarf", "Elf", };

  public static String name(int e) { return names[e - None]; }
}
