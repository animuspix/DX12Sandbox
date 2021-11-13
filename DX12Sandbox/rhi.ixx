export module rhi;

namespace rhi
{
	// Command lists/qs in an rhi::scheduling namespace
	// One graphics command-list/queue, one compute
	// command-list/queue
	//////////////////////////////////////////////////

	// Textures, buffers, targets in an rhi::resrces namespace
	//////////////////////////////////////////////////////////

	// Shaders (PSOs) in an rhi::tasks namespace
	// Two optionssss
	// Parsing - domain-specific HLSL superset with input/output hints, shader stages
	//			 all in one file
	// Generative - Shaders composed at startup from C++ code & expected bindings
	// Generative should be MUCH easier to maintain and also fun af to write :D
	// Just going to need a lot of "operation" structures with a .reflect() member to generate their corresponding HLSL text
	// See option 4 here for how to get dxil from the generative approach with DXC:
	// https://asawicki.info/news_1719_two_shader_compilers_of_direct3d_12
	// Tasks should specify any dependencies (whether they expect to launch/be launched by any indirect workers, or whether they
	// require inputs in a specific state), and also workgroup dimensions for compute work; graphics tasks should flag which
	// of their resources is the vertex-buffer/accessed through a VBV by the vertex shader, and validate that outputs from the VS
	// match inputs for the PS during compilation/codegen
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Descriptor management works like:
	// - Resource structures purely control resource memory (vram)
	// - Descriptors to use are implicit in Task inputs & outputs (inferred during PSO compilation - input/output operations would be required to specify a resource)
	//   -> Just before the first frame, the scheduling system would sort Tasks by resource state + dependencies (so we maximize the number of events we can issue before
	//		we hit transition barriers, but without breaking things like indirect draw/dispatch), then iterate through each Task and allocate + initialize their descriptors
	//		in a shared heap (managed by rhi::mem); after we generate those subsets of the descriptor heap we can comfortably generate descriptor tables + root descriptors
	//		for each Task :D
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Resource & descriptor memory in an rhi::mem namespace
	////////////////////////////////////////////////////////

	// Geometry processing in rhi::geometry
	///////////////////////////////////////

	// Data marshalling (upload/download to/from gpu) in rhi::messenger
	///////////////////////////////////////////////////////////////////

	// Should orient my core pipeline around a visbuffer
	// (RHI renders tri IDs tagged with materials & background data (transparent materials only) every frame, and takes that buffer as input for every other pass)
	// Should probably run culling + screenspace LOD (collapsing triangles that are ~coplanar along camera-Z) in compute, then feed the vertices/indices resolved
	// from there along to the visbuffer pass (which pushes the minimal triangle ID buffer along to future passes for shading)
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Core RHI initializes the swapchain & device (ID3D12Device9, newest available), then initializes the rhi subsystems described above
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	bool init()
	{

	}
};