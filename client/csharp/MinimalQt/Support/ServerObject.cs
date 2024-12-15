namespace Org.Whatever.MinimalQt.Support
{
    internal abstract class ServerObject(int id) : ServerResource(id)
    {
        protected override void NativePush()
        {
            NativeMethods.pushInstance(Id, false);
        }
    }
}
