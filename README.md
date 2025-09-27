# VertexAnimationEditorUtils
Automating VAT creation, to be used with the VertexAnimationManager plugin in UE5

To use:

1. Clone/pull this repo and add a folder to your project's Plugins/ folder called VertexAnimationEditorUtils.
2. Enable this plugin for your project.
3. Add a "Has VAT" static switch to your skeletal mesh's material (see All/VertexAnimationEditorUtils/M_ExampleMaterial in Unreal Editor for an example of how to do this)
4. Right click the skeletal mesh -> "Scripted Asset Actions" -> "Create VAT for Skeletal Mesh"
5. Add the animations you want to create VATs for
6. When prompted, select the Vertex Animation Profile with an asterisk (this is the new VAT profile to be used)
7. All materials, textures, and parameters will be assigned.
8. Add the Vertex Animation Profile to your VARuntime in your Blueprint.

And you're done!

If you want to change the options (number of bone influences, nanite enabled, etc) then you can open All/VertexAnimationEditorUtils/EBP_VAT_SkeletalMeshBaker and adjust the variables for those settings on the left.