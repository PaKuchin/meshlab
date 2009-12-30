/**
 * @author Vitillo Roberto Agostino <vitillo@cli.di.unipi.it>
 */

#ifndef MESHSUBFILTER_H
#define MESHSUBFILTER_H

#include <meshlab/meshmodel.h>
#include <meshlab/interfaces.h>

#include <vcg/math/matrix44.h>

#include <vector>

class MeshSubFilter{
public:
    MeshSubFilter();
    virtual void initParameterSet(QAction* action,MeshDocument& md, RichParameterSet & par);
    virtual bool applyFilter(QAction* filter, MeshDocument &md, RichParameterSet& par, vcg::CallBackPos* cb);

protected:
    typedef std::vector<vcg::Matrix44f> LayerTransformations;
    typedef std::vector<LayerTransformations> LayersTransformations;

    virtual void initialize(MeshDocument&, RichParameterSet&) = 0;
    virtual bool configurationHasChanged(RichParameterSet& par);

    int m_steps;
    int m_seconds;
    const float m_stepSize;
    LayersTransformations m_layersTrans;
};

#endif // MESHSUBFILTER_H